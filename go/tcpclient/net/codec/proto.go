package codec

import (
	"QuickStart/go/tcpclient/common"
	"QuickStart/go/tcpclient/net/tcp"
	"bytes"
	"encoding/binary"
	"errors"
	"github.com/golang/protobuf/proto"
)

type ProtoClientProtocol struct {
	Endian_ binary.ByteOrder
	Parse_  bool //是否解包
}

func (p *ProtoClientProtocol) NewCodec() tcp.Codec {
	return &ProtoClientCodec{
		Endian_: p.Endian_,
		Parse_:  p.Parse_,
	}
}

type ProtoClientCodec struct {
	Endian_ binary.ByteOrder
	Parse_  bool //是否解包
}

// 编码包头和包体成消息
func (bc *ProtoClientCodec) Marshal(v interface{}) ([]byte, error) {
	msg, ok := v.([]interface{})
	if !ok {
		return nil, errors.New("ProtoClientCodec Marshal invalid data")
	}

	msgHead, ok := msg[0].(*common.ProtocolClientHead)
	if !ok {
		return nil, errors.New("ProtoClientCodec Marshal data has not ProtocolClientHead head")
	}

	buf := bytes.NewBuffer(nil)
	err := binary.Write(buf, bc.Endian_, msgHead)
	if err != nil {
		return nil, err
	}
	if len(msg) == 2 {
		var bodyData []byte
		var err error
		body, ok := msg[1].(proto.Message)
		if ok {
			bodyData, err = proto.Marshal(body)
			if err != nil {
				return nil, err
			}
		} else {
			bodyData, ok = msg[1].([]byte)
			if !ok {
				return nil, errors.New("ProtoClientCodec Marshal data proto-msg must be proto or []byte")
			}
		}
		err = binary.Write(buf, bc.Endian_, bodyData)
		if err != nil {
			return nil, err
		}
	}

	return buf.Bytes(), nil
}

// 解析除消息长度之外的字节，解析为消息头和消息体
func (bc *ProtoClientCodec) Unmarshal(data []byte) (interface{}, error) {

	var msg []interface{}
	//解码成一个消息结构体
	msgHead := &common.ProtocolClientHead{}

	bufData := bytes.NewBuffer(data)
	err := binary.Read(bufData, binary.BigEndian, msgHead)
	if err != nil {
		return nil, err
	}

	msg = append(msg, msgHead)

	//包头之后是具体的消息内容
	bufLen := bufData.Len()
	if bufLen > 0 {
		msg = append(msg, bufData.Bytes())

		//todo 以后有了proto 消息handler，可以在此解析成proto结构体
		if bc.Parse_ {

		}
	}

	return msg, nil
}

type ProtoInnerProtocol struct {
	Endian_ binary.ByteOrder
	Parse_  bool
}

func (p *ProtoInnerProtocol) NewCodec() tcp.Codec {
	return &DTFishInnerProtoCodec{
		Endian_:    p.Endian_,
		Parse_:     p.Parse_,
		Game_type_: 97,
	}
}

type ProtoInnerCodec struct {
	Endian_ binary.ByteOrder
	Parse_  bool
}

// 编码包头和包体成消息
func (bc *ProtoInnerCodec) Marshal(v interface{}) ([]byte, error) {
	msg, ok := v.([]interface{})
	if !ok {
		return nil, errors.New("ProtoInnerCodec Marshal invalid data")
	}

	msgHead, ok := msg[0].(*common.ProtocolInnerHead)
	if !ok {
		return nil, errors.New("ProtoInnerCodec Marshal data has not ProtocolInnerHead head")
	}

	data, err := msgHead.Write(bc.Endian_)
	if err != nil {
		return nil, err
	}

	buf := bytes.NewBuffer(nil)
	err = binary.Write(buf, bc.Endian_, data)
	if err != nil {
		return nil, err
	}

	if len(msg) == 2 {
		var bodyData []byte
		var err error
		body, ok := msg[1].(proto.Message)
		if ok {
			bodyData, err = proto.Marshal(body)
			if err != nil {
				return nil, err
			}
		} else {
			bodyData, ok = msg[1].([]byte)
			if !ok {
				return nil, errors.New("ProtoInnerCodec Marshal data proto-msg must be proto or []byte")
			}
		}
		err = binary.Write(buf, bc.Endian_, bodyData)
		if err != nil {
			return nil, err
		}
	}

	return buf.Bytes(), nil
}

// 解析除消息长度之外的字节，解析为消息头和消息体
func (bc *ProtoInnerCodec) Unmarshal(data []byte) (interface{}, error) {
	//解码头部
	buf := bytes.NewBuffer(data)
	msgHead := &common.ProtocolInnerHead{}
	err := msgHead.Read(buf, bc.Endian_)
	if err != nil {
		return nil, err
	}

	var msg []interface{}
	msg = append(msg, msgHead)

	//包头之后是具体的消息内容
	if buf.Len() > 0 {
		msg = append(msg, buf.Bytes())

		//todo 以后有了proto 消息handler，可以在此解析成proto结构体
		if bc.Parse_ {

		}
	}

	return msg, nil
}
