package tcpclient

import (
	"QuickStart/go/tcpclient-dtfish/net/tcp"
	pb "QuickStart/go/tcpclient-dtfish/proto"
	"QuickStart/go/utils"
	"testing"
)

// 玩机甲轮盘的前置条件
func jijialunpanPlayPreconditions(session *tcp.Session, uid uint64) {
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_SHOP_EXCHANGE_DELIVERY, &pb.PBCsGameShopExchangeDeliveryReqMsg{ProductId: 101010301, Count: 500})
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK, &pb.JiJiaLunPanPickReq{ItemId: 9001})
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK, &pb.JiJiaLunPanPickReq{ItemId: 4008})
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK, &pb.JiJiaLunPanPickReq{ItemId: 14001})
}

// 机甲轮盘玩到抽到所有自选奖励
func TestJijialunpanPlay(t *testing.T) {
	session, uid, _ := newSession()
	jijialunpanPlayPreconditions(session, uid)
	for {
		resp := sendAndReturnResp(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PLAY, &pb.JiJiaLunPanPlayReq{Times: 1}).(*pb.JiJiaLunPanPlayResp)
		if !resp.Finish {
			continue
		}
		utils.PrintJson(resp)
		break
	}
}
