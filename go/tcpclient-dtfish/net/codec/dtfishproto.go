package codec

import (
	"QuickStart/go/tcpclient-dtfish/common"
	"QuickStart/go/tcpclient-dtfish/net/tcp"
	DTFishProtoMsg "QuickStart/go/tcpclient-dtfish/proto/dtfish"
	"encoding/binary"
	"errors"
	"github.com/golang/protobuf/proto"
)

type DTFishClientProtoProtocol struct {
	Endian_ binary.ByteOrder
	Parse_  bool //是否解包

	Game_type_ int32 //表示固定的游戏类型

}

const (
	dtfish_default_version = 1
)

func (this *DTFishClientProtoProtocol) NewCodec() tcp.Codec {
	return &DTFishClientProtoCodec{
		Endian_:    this.Endian_,
		Parse_:     this.Parse_,
		Game_type_: this.Game_type_,
	}
}

type DTFishClientProtoCodec struct {
	Endian_ binary.ByteOrder
	Parse_  bool

	Game_type_ int32 //表示固定的游戏类型
}

// 编码包头和包体成消息
func (this *DTFishClientProtoCodec) Marshal(v interface{}) ([]byte, error) {
	msg, ok := v.([]interface{})
	if !ok {
		return nil, errors.New("DTFishClientProtoCodec Marshal invalid data")
	}

	msg_head, ok := msg[0].(*common.ProtocolClientHead)
	if !ok {
		return nil, errors.New("DTFishClientProtoCodec Marshal data has not ProtocolClientHead head")
	}

	packet := &DTFishProtoMsg.Packet{
		Gametype:       proto.Int32(this.Game_type_),
		Command:        proto.Uint32(msg_head.Msg_id_),
		UserID:         proto.Uint64(msg_head.Uid_),
		Version:        proto.Uint32(dtfish_default_version),
		SequenceNumber: proto.Uint64(uint64(msg_head.Seq_)),
	}

	if len(msg) == 2 {
		var body_data []byte
		var err error
		body, ok := msg[1].(proto.Message)
		if ok {
			body_data, err = proto.Marshal(body)
			if err != nil {
				return nil, err
			}
		} else {
			body_data, ok = msg[1].([]byte)
			if !ok {
				return nil, errors.New("DTFishClientProtoCodec Marshal data protomsg must be proto or []byte")
			}
		}

		packet.Serialized = body_data
	}

	packet_data, err := proto.Marshal(packet)
	if err != nil {
		return nil, err
	}

	return packet_data, nil
}

// 解析除消息长度之外的字节，解析为消息头和消息体
func (this *DTFishClientProtoCodec) Unmarshal(data []byte) (interface{}, error) {
	packet := &DTFishProtoMsg.Packet{}
	err := proto.Unmarshal(data, packet)
	if err != nil {
		return nil, err
	}

	msg := []interface{}{}
	if packet.UserID == nil {
		return nil, errors.New("Packet logic need field nil")
	}

	head := &common.ProtocolClientHead{
		Msg_id_: *packet.Command,
		Uid_:    *packet.UserID,
	}

	if packet.SequenceNumber != nil {
		head.Seq_ = uint32(*packet.SequenceNumber)
	}

	msg = append(msg, head)
	msg = append(msg, packet.Serialized)

	//todo 以后有了proto 消息handler，可以在此解析成proto结构体
	if this.Parse_ {

	}

	return msg, nil
}

type DTFishInnerProtoProtocol struct {
	Endian_ binary.ByteOrder
	Parse_  bool //是否解包

	Game_type_ int32 //表示固定的游戏类型
	Game_code_ int32
}

func (p *DTFishInnerProtoProtocol) NewCodec() tcp.Codec {
	return &DTFishInnerProtoCodec{
		Endian_:    p.Endian_,
		Parse_:     p.Parse_,
		Game_type_: p.Game_type_,
		Game_code_: p.Game_code_,
	}
}

type DTFishInnerProtoCodec struct {
	Endian_ binary.ByteOrder
	Parse_  bool

	Game_type_ int32 //表示固定的游戏类型
	Game_code_ int32
}

// 编码包头和包体成消息
func (this *DTFishInnerProtoCodec) Marshal(v interface{}) ([]byte, error) {
	msg, ok := v.([]interface{})
	if !ok {
		return nil, errors.New("DTFishInnerProtoCodec Marshal invalid data")
	}

	packet, ok := msg[0].(*common.DTFishProtocolInnerHead)
	if !ok {
		return nil, errors.New("DTFishInnerProtoCodec Marshal data has not DTFishProtocolInnerHead head")
	}

	if packet.Version == nil {
		packet.Version = proto.Uint32(dtfish_default_version)
	}

	if packet.Gametype == nil {
		packet.Gametype = proto.Int32(this.Game_type_)
	}

	if packet.GameCode == nil {
		packet.GameCode = proto.Int32(this.Game_code_)
	}

	if len(msg) == 2 {
		var body_data []byte
		var err error
		body, ok := msg[1].(proto.Message)
		if ok {
			body_data, err = proto.Marshal(body)
			if err != nil {
				return nil, err
			}
		} else {
			body_data, ok = msg[1].([]byte)
			if !ok && msg[1] != nil {
				return nil, errors.New("DTFishInnerProtoCodec Marshal data protomsg must be proto or []byte")
			}
		}

		packet.Serialized = body_data
	}

	packet_data, err := proto.Marshal(&packet.Packet)
	if err != nil {
		return nil, err
	}

	return packet_data, nil
}

// 解析除消息长度之外的字节，解析为消息头和消息体
func (this *DTFishInnerProtoCodec) Unmarshal(data []byte) (interface{}, error) {
	packet := &DTFishProtoMsg.Packet{}
	err := proto.Unmarshal(data, packet)
	if err != nil {
		return nil, err
	}

	msg := []interface{}{}
	head := &common.DTFishProtocolInnerHead{
		Packet: *packet,
	}

	msg = append(msg, head)
	msg = append(msg, packet.Serialized)

	//todo 以后有了proto 消息handler，可以在此解析成proto结构体
	if this.Parse_ {

	}

	return msg, nil
}
