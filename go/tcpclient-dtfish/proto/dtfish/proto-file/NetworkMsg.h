#ifndef NETWORK_MSG_H_
#define NETWORK_MSG_H_

#define LOGINSERVER_LATEST_CMD_VERSION      0
#define LOGINSERVER_MIN_SUPPORT_CMD_VERSION 0

//由于在同一个 agent 下会挂很多类型的游戏，gamecode 已经不能准确标记所有玩法的 游戏类型了，特增加GameClass作为 游戏的总类型，GameCode 作为标记agent 类型
enum SUPPORT_GAME_TYPE
{
	kTexasPoker = 0,
	kNiuNiu = 1,
	kBaccarat = 2,
	kZhaJinHua = 3, 
	kSlots = 4,
	kRoulette = 5,
	kDouDiZhu = 6,
	kStud = 7,
	kGuanDan = 8,
	kBlackJack = 9,
	kNiuNiuQiangZhuang = 10,
	kShiSanZhang = 11,
	kBuYuOL = 12,	//FishingOL ShanDong Dev
	kFishingOnline = 13, //FishingOnline 1
	kMaJiang2P = 14,
	kLKPY = 15,
	kTeenPatti = 16,
	kOkey = 17,
	kMaJiang = 18,
	kVideoArcade = 19,
	kDouDiZhuTournament = 20,
	kShengJi = 21,
	kPaoDeKuai = 22,
	kMJZJ = 23,
	kDaDaA = 24,
	kBaoHuang = 25,
	kMJXUEZHAN = 26,
	kMJXUEZHANDD = 27,
	kShuangKou = 28,
	kGuanDanZhiBo = 29,
	kLobby = 30,
	kMaJiangGuoBiao = 31,
	kMaJiangHangZhou = 32,
	kDouDiZhuZhiBo = 33,
	kMaJiangGuangDong = 34,
	//kMaJiangGuangDongJiPingHu = 35,
	kSanKouYi = 36,
	kMaJiangNanJing = 37,
	kMaJiangJiangSuFriend = 38,
	kMaJiangJiangXi = 39,
	kMaJiangZheJiangFriend = 40,
	kMaJiangNeiMengGuFriend = 41,
	KChinaChess = 42,
	kMaJiangNewXueLiu = 43,
	kPaoYao = 44,
	kJiSuPuKe = 45,
	KErQiWang = 46,
	kGanDengYan = 47,
	kMaJiangErRenGuoBiao = 48,
	kMaJiangHeNan = 49,
	kMaJiangHuanLe = 50,
	kPinFan = 51,
	kGomoku = 52,
	kPaoHuZi = 53,
	kMaJiangZhuoJiEx = 54,
	kActivity = 55,
	kDouDiZhuBaiRenJingCai = 56,
	kMaJiangJapanese = 57,
	kAirplane = 58,
	kMaJiangAll = 59,

	kThailandPoker = 200,
	kThailandPokDeng = 201,
	kThailandPaiKeang = 202,
	kThailandDummy = 203,
	kThailandDoubleTen = 204,
	kThailandTouZi = 205,
	kThailandYuXiaXie = 206,
	kThailandDomino = 207,
	kThailandAll = 208,
	kBaiRenThailandPoker = 209,//百人三公
	//reserved from 10000
	//the values are used just for login/register history statistics 
	//to distinguish old/new pay process
};

//由于在同一个 agent 下会挂很多类型的游戏，gamecode 已经不能准确标记所有玩法的 游戏类型了，特增加GameClass作为 游戏的总类型，GameCode 作为标记agent 类型
//目前给战绩统计模块使用
//格式说明 前三位 是类型号 如 100 是扑克类 后三位 游戏编号
enum GAME_CLASS
{
	gcStart = 0,
	//100 扑克类
	gcDouDiZhu = 100001,
	gcDaDaA = 100002,
	//200 麻将
	//300 休闲游戏
	//400 拉霸类
	gcEnd
};

enum LianZongMsg
{
	kConnectToLianZong = 1001,
	kLianZongConnected = 1002,
	kLianZongDisconnected = 1003,
	THRANID_SVR_PAYCONN = 0x00002001,
	THRANID_SVR_PAYCONN_RESPONSE = 0x08002001,
};

enum EnumFishPacketTargetType
{
	enumFishPacketLogic2Client = 0,
	enumFishPacketLogic2MiddleLayer = 1,
	enumFishPacketLogic2RankingServer = 2,
};

enum EnumPokerPacketTargetType
{
	enumPokerPacketLogic2Client = 0,//房间给客户端
	enumPokerPacketLogic2MiddleLayer = 1,//房间给中间层
	enumPokerPacketAgent2LogicTable = 2,//agent给房间桌子
	enumPokerPacketAgent2LogicSmc,//agent给房间的gm指令
	enumPokerPacketLogic2MiddleLayer2Client,//房间给中间层再返回客户端,为了保证时序
	enumPokerPacketMiddleLayer2OtherMiddleLayer,//中间层给别的中间层
	enumPokerPacketAgent2MaJiangLogicTable,	//agent给麻将桌子
};

enum EnumPokerGamePlayType
{
	enumPokerGamePlayTypeFree = 1,
	enumPokerGamePlayTypeTournament,
	enumPokerGamePlayTypeFriend,
	enumPokerGamePlayTypeBaiRen,
};

enum EnumPokerGameDetailPlayType
{
	enumPokerGameDetailPlayTypeFree = 1,
	enumPokerGameDetailPlayTypeTournamentNewHuaFei,
	enumPokerGameDetailPlayTypeTournamentWinStreak,
	enumPokerGameDetailPlayTypeFriend,
	enumPokerGameDetailPlayTypeRankingMatch,
	enumPokerGameDetailPlayTypeAIChallengeMatch,
};

enum EnumServerType
{
	enumServerTypeChina = 0,
	enumServerTypeFish = 1,
	enumServerTypeThailand = 2,
	enumServerTypeIndonesia = 3,
	enumServerTypeTouTiao = 4,
	enumServerTypeHago = 5,
	enumServerTypeXiaoYouXi = 6,
	enumServerTypeAirplane = 7,
};

enum EnumPayMethod
{
	enumGooglePay = 1,
	enumSmsPay,
	enumPinCode1Pay,
	enumPinCode2Pay,
	enumTrueWalletPay,
};

enum NETWORK_MSG
{
    //gui与client network layer之间内部交互的命令字，暂定<=10000
    
    //status msg
    kDispatchConnected = 1,
    kDispatchDisconnected,
    kRoomConnected,
    kRoomDisconnected,
	kOnAndroidJNIResponse,
    
    //send msg
    //dispatch msg
	kConnectToDispatch,
    //room msg
    kConnectToRoom,
    kRoomKeepAlive,
	kDisconnectRoom,
	
    kMaxClientInternalMsg = 10000,
    
    //client与loginserver之间交互的命令字，暂定10000<= && <=20000
    kGetGameServerList         = 10001,
	kGetGameServerListResponse = 10002,
	kGameServerToLoginServerReportPlayerLoginInfo = 10003,
    kMaxClientLoginServerMsg   = 20000,
    
    //client与gameserver之间交互的命令字，暂定20000<= && <=50000
    kGameServerLoginRequest = 20001,
	kGameServerLoginResponse,
	kGameServerGetUserBasicInfoRequest,//no use
	kGameServerGetUserBasicInfoResponse,//no use
	kGameServerGetUserDetailInfoRequest,//no use
	kGameServerGetUserDetailInfoResponse,//no use
	kGameServerGetTableListRequest,
	kGameServerGetTableListResponse,
	kGameServerEnterTableRequest,
	kGameServerEnterTableResponse,
	kGameServerEnterTableBC,
	kGameServerEnterSeatRequest,
	kGameServerEnterSeatResponse,
	kGameServerEnterSeatBC,
	kGameServerLeaveSeatRequest,
	kGameServerLeaveSeatResponse,
	kGameServerLeaveSeatBC,
	kGameServerLogicData,
	kGameServerKeepAlive,
	kGameServerEnterGameRequest,
	kGameServerEnterGameResponse,
	kGameServerModifyTakeInScoreRequest,
	kGameServerModifyTakeInScoreResponse,
	kGameServerModifyTakeInScoreBC,
	kGameServerLeaveTableRequest,
	kGameServerLeaveTableResponse,
	kGameServerGetGameListRequest,
	kGameServerGetGameListResponse,
	kGameServerQuickStartRequest,
	kGameServerQuickStartResponse,
	kGameServerQueryUserInfoRequest,
	kGameServerQueryUserInfoResponse,
	kGameServerBonusChips,
	kGameServerKickDuplicateUser,
	kGameServerModifyUserInfoRequest,
	kGameServerModifyUserInfoResponse,
	kGameServerLeaveGameRequest,
	kGameServerLeaveGameResponse,
    kGameServerAdWallAdChips,
	kGameServerTotalScoreChanged,
	kGameServerAddFriendRequest,
	kGameServerAcceptFriendRequest,
	kGameServerRejectFriendRequest,
	kGameServerRemoveFriendRequest,
	kGameServerRemoveFriendResponse,
	kGameServerRemoveFriendBC,
	kGameServerGetAddFriendRequestListRequest,
	kGameServerGetAddFriendRequestListResponse,
	kGameServerGetFriendListRequest,
	kGameServerGetFriendListResponse,
	kGameServerSearchUserRequest,
	kGameServerSearchUserResponse,
	kGameServerSingleChatMsg,
	kGameServerGetOfflineMsgRequest,
	kGameServerGetOfflineMsgResponse,
	kGameServerAcceptFriendResponse,
	kGameServerTableChat,
	kGameServerPresentScoreRequest,
	kGameServerPresentScoreResponse,
    kGameServerQueryUserPropertyRequest,
    kGameServerQueryUserPropertyResponse,
    kGameServerBuyPropertyRequest,
    kGameServerBuyPropertyResponse,
    kGameServerSellPropertyRequest,
    kGameServerSellPropertyResponse,
	kGameServerBuyGiftRequest,
	kGameServerBuyGiftResponse,
	kGameServerQueryGiftInfoByIDRequest,
	kGameServerQueryGiftInfoByIDResponse,
	kGameServerChangeScoreWithOldConnection,
	kGameServerOnlineRewardDefine,
	kGameServerOnlineRewardRequest,
	kGameServerOnlineRewardResponse,
	kGameServerSubSpeakerRequest,
	kGameServerSubSpeakerResponse,
	kGameServerTableRewardPoolInfo,
	kGameServerTableReward,
    kGameServerStartRouletteRequest,
    kGameServerStartRouletteResponse,
    kGameServerQueryNotificationRequest,
    kGameServerQueryNotificationResponse,
    kGameServerBuySpeakerRequest,
    kGameServerBuySpeakerResponse,
    kGameServerStartRouletteNewRequest,
    kGameServerStartRouletteNewResponse,
	kGameServerKickUserFromTableRequest,
	kGameServerKickUserFromTableResponse,
	kGameServerTryKickUserFromTableRequest,
	kGameServerTryKickUserFromTableResponse,
    kGameServerExchangeToolRequest,
    kGameServerExchangeToolResponse,
	kGameServerTaskToDoNotify,
	kGameServerTaskFinishNotify,
    kGameServerNotificationAddNotify,
    kGameServerNotificationDeleteNotify,
    kGameServerQueryActivityRequest,
    kGameServerQueryActivityResponse,
    kGameServerActivityAddNotify,
    kGameServerActivityDeleteNotify,
	kGameServerChangeTableRequest,
	kGameServerChangeTableResponse,
    kGameServerBroadcastNotify,
    kGameServerQueryMissionRequest,
    kGameServerQueryMissionResponse,
    kGameServerQueryExchangeProductListRequest,
    kGameServerQueryExchangeProductResponse,
    kGameServerExchangeProductRequest,
    kGameServerExchangeProductResponse,
    kGameServerQueryTryLuckListRequest,
    kGameServerQueryTryLuckListResponse,
    kGameServerStartTryLuckRequest,
    kGameServerStartTryLuckResponse,
    kGameServerQueryExchangeHisRequest,
    kGameServerQueryExchangeHisResponse,
    kGameServerStartRouletteLianZhongRequest,
    kGameServerStartRouletteLianZhongResponse,
	kGameServerMissionComplete,
	kGameServerGetMissoinRewardRequest,
	kGameServerGetMissoinRewardResponse,
	kGameServerMissionIng,
	kGameServerGetTournamentGameListRequest,
	kGameServerGetTournamentGameListResponse,
	kGameServerGetTournamentConfigRequest,
	kGameServerGetTournamentConfigResponse,
	kGameServerGetTournamentPlayerCountRequest,
	kGameServerGetTournamentPlayerCountResponse,
	kGameServerApplyTournamentRequest,
	kGameServerApplyTournamentResponse,
	kGameServerExitTournamentRequest,
	kGameServerExitTournamentResponse,
	kGameServerTournamentGameStart,
	kGameServerTournamentPlacingChanged,
	kGameServerTournamentPromotion,
	kGameServerTournamentPromotionInfoChanged,
	kGameServerTournamentResult,
	kGameServerTournamentApplyUserCountChanged,
	kGameServerGetUserCurrentSignInMapRequest,
	kGameServerGetUserCurrentSignInMapResponse,
	kGameServerUserSignInRequest,
	kGameServerUserSignInResponse,
	kGameServerUserSignInRewardNotify,
	kGameServerMissionProgress,

	kGameServerNewGetTournamentGameTypeRequest,
	kGameServerNewGetTournamentGameTypeResponse,
	kGameServerNewGetTournamentGameRoomListRequest,
	kGameServerNewGetTournamentGameRoomListResponse,
	kGameServerNewGetTournamentGameConfigRequest,
	kGameServerNewGetTournamentGameConfigResponse,
	kGameServerNewGetTournamentPlayerCountRequest,
	kGameServerNewGetTournamentPlayerCountResponse,
	kGameServerNewApplyTournamentRequest,
	kGameServerNewApplyTournamentResponse,
	kGameServerNewTournamentApplyUserCountChanged,
	kGameServerNewExitTournamentRequest,
	kGameServerNewExitTournamentResponse,
	kGameServerNewTournamentGameStart,
	kGameServerNewTournamentPlacingChanged,
	kGameServerNewTournamentResult,

	kGameServerQueryOnlineGameStatus,
	kGameServerForbidUserActionNotify,
	kGameServerAllowUserActionNotify,

	kGameServerOffline2OnlineRequest,
	kGameServerOffline2OnlineResponse,
	kGameServerUserOfflineNotify,
	kGameServerUserActionBlockedNotify,

	kGameServerAddictionPreventionNotify,
	kGameServerInGameTaskNotify,
	kGameServerInGameTaskFinishNotfify,

	kGameServerQueryUserBaggageInfoRequest,
	kGameServerQueryUserBaggageInfoResponse,
	kGameServerCofferOperationRequest,
	kGameServerCofferOperationResponse,
	
	kGameServerGuestRegistRequest,
	kGameServerGuestRegistResponse,

	kGameServerQueryUserSignInStatusRequest,
	kGameServerQueryUserSignInStatusResponse,
	kGameServerSignInRequest,
	kGameServerSignInResponse,
	kGameServerGetSignInRewardRequest,
	kGameServerGetSignInRewardResponse,

	kGameServerLaoHuJiGetGameConfigRequest,
	kGameServerLaoHuJiGetGameConfigResponse,
	kGameServerLaoHuJiGameStartRequest,
	kGameServerLaoHuJiGameStartResponse,
	kGameServerLaoHuJiGetRewardListRequest,
	kGameServerLaoHuJiGetRewardListResponse,
	kGameServerLaoHuJiGetWinHistoryRequest,
	kGameServerLaoHuJiGetWinHistoryResponse,

	kGameServerUseNoteCardDevice,

	kGameServerLaoHuJiAddOneGameRecord,
	
	kGameServerQueryRouletteConfig,
	kGameServerDoRoulette,
	kGameServerQueryRankInfo,

	kGameServerQueryIsUserInTournamentRequest,
	kGameServerQueryIsUserInTournamentResponse,
	
	kGameServerGetRankReward,

	kGameServerAddPreApplyUserRequest,
	kGameServerRemovePreApplyUserRequest,

	kGameServerSendAnimationEmotionRequest,
	kGameServerSendAnimationEmotionResponse,

	kGameServerBuyNewGiftRequest,
	kGameServerBuyNewGiftResponse,
	kGameServerSellNewGiftRequest,
	kGameServerSellNewGiftResponse,
	kGameServerUseNewGiftRequest,
	kGameServerUseNewGiftResponse,
	kGameServerQueryUserNewGiftsRequest,
	kGameServerQueryUserNewGiftsResponse,

	kGameServerTournamentWillStartNotify,

	kGameServerAddPreApplyUserResponse,
	kGameServerTournamentWaitCombineTablesNotify,
	kGameServerTournamentBaseScoreWillChange,
	kGameServerAddTournamentGameDingShiSaiAttentionUserRequest,
	kGameServerAddTournamentGameDingShiSaiAttentionUserResponse,//no use
	kGameServerRemoveTournamentGameDingShiSaiAttentionUserRequest,
	kGameServerTournamentDingShiSaiChanged,
	kGameServerQueryUserTournamentStatRequest,
	kGameServerQueryUserTournamentStatResponse,

	kGameServerQuickStartPayAfterBankrupt,
	
	kGameServerAddTableAttentionUserRequest,
	kGameServerAddTableAttentionUserResponse,
	kGameServerRemoveTableAttentionUserRequest,
	
	kGameServerAddSuperWatcherRequest,
	kGameServerAddSuperWatcherResponse,
	
	kGameServerExchangeHuaFei,

	kGameServerTournamentCombineTablesNotify,
	
	kGameServerExchangeHuaFeiQuanToCouponNotify,

	kGameServerTournamentFinalTableNotify,
	kGameServerTournamentValidTimeNotify,

	kGameServerExchangeCouponToChip,
	kGameServerGetRoomListRequest,
	kGameServerGetRoomListResponse,
	kGameServerChangeSeatRequest,
	kGameServerChangeSeatResponse,
	kGameServerNewGetTableListRequest,
	kGameServerNewGetTableListResponse,
	kGameServerTableStatusChangedNotify,

	kGameServerRouletteEnergyPointRequest,
	kGameServerRouletteEnergyPointResponse,
	kGameServerRouletteConfigRequest,
	kGameServerRouletteConfigResponse,
	kGameServerRoulettePlayRequest,
	kGameServerRoulettePlayResponse,
	kGameServerRouletteNotify,
	kGameServerEscapePunishmentNotify,
	kGameServerRewardForOtherEscapeNotify,
	
	kGameServerUseMotor,
	kGameServerGetPovertyReward,
	
	kGameServerPresentItem,
	kGameServerQueryPresentItemRequestList,
	kGameServerAcceptPresentItem,
	kGameServerUseItem,

	kGameServerModifyPassword,
	kGameServerResetPassword,
	kGameServerBindMobileNumber,
	kGameServerUnbindMobileNumber,
	
	kGameServerPresentItemFromOther,
	
	kGameServerSwitchGame,

	kGameServerCreatePrivateTable,
	kGameServerGetTVTournamentListRequest,
	kGameServerGetTVTournamentListResponse,
	kGameServerGetTVTournamentDateRangeRequest,
	kGameServerGetTVTournamentDateRangeResponse,

	kGameServerWatchTVGameRequest,
	kGameServerWatchTVGameResponse,
	kGameServerControlTVGameRequest,
	kGameServerControlTVGameResponse,
	
	kGameServerUpdateUserLocation,
	kGameServerQueryUserLocation,

	kGameServerQueryUserExtraInfo,
	kGameServerGetBuyReward,

	kGameServerFriendOperation,
	kGameServerFriendOperationAck,
	kGameServerGetFriendInfo,

	kGameServerTableInfoChangeNotify,

	kGameServerSearchFriend,

	kGameServerQuerySystemBroadcast,

	kGameServerUserTakeInScoreChangeNotify,
	kGameServerReturnToMainMenuNotify,
	kGameServerModifyFriendRemarkNick,
	kGameServerGetFreeTournamentListRequest,
	kGameServerGetFreeTournamentListResponse,
	kGameServerFreeTournamentResult,
	kGameServerSlotTournamentResult,
	
	kGameServerGetVipReward,
	kGameServerReplayTVGameRequest,
	kGameServerReplayTVGameResponse,

	kGameServerSetUserAutoTakeInScore,
	kGameServerGetVerificationCode,
	kGameServerResetPasswordNew,

	kGameServerSetLoginProtection,//expired
	kGameServerLoginVerification,

	kGameServerGameServerCloseNotify,

	kGameServerQueryRewardStatus,
	kGameServerGetWechatShareReward,

	kGameServerExchangeRealHuaFeiRequest,
	kGameServerExchangeRealBodyRequest,
	kGameServerExchangeRealResponse,

	kGameServerQueryAllRoomConfig,
	kGameServerClientNotifyGameStopFinished,
	kGameServerNewTournamentPlacingChangedPreGameStart,
	kGameServerNewTournamentPlacingChangedAfterGameStop,
	kGameServerQueryRoomTournamentStat,
	kGameServerTournamentWinStreakResult,
	kGameServerExchangeTournamentScore,
	kGameServerQueryAllRoomStatus,

	kGameServerReplayTVGameTimesRequest,
	kGameServerReplayTVGameTimesResponse,

	kGameServerClientLeaveOut,
	kGameServerServerLeaveOut,

	kGameServerGetVerificationCodeNewMobile,
	kGameServerGuestRegistByMobile,
	kGameServerGetIosGradeReward,
	kGameServerNewCofferOperationRequest,
	kGameServerModifyCofferNewPassword,
	kGameServerResetCofferNewPassword,
	kGameServerGuestRegistWeChatAccount,
	
	kGameServerAcceptPresentItemToTable,

	kGameServerGuestRegistQQAccount,
	kGameServerQueryNewRouletteConfig,
	kGameServerPlayNewRoulette,
	kGameServerDetectNetwork,
	kGameServerGetWechatShareRewardNew,

    kGameServerHaoYouCreateTableRequest =20324,
    kGameServerHaoYouCreateTableResponse = 20325,

	kGameServerHaoYouGetTableMsgRequest = 20326 ,
    kGameServerHaoYouGetTableMsgResponse = 20327,
	
	kGameServerUseWechatRedPacket,

	kClientYanZhenMaRequest,
	kServerYanZhenMaResponse,
	kClientSendHongBaoRequest,
	kServerSendHongBaoResponse,
	kHttpServerNotResponse,
    kClientBindListRequest,
    kServerBindListResponse,

	kGameServerGetVipDailyReward,
	kGameServerDisbandFriendTableVote,
	kGameServerUserActionInvalidNotify,
	kGameServerQueryUserFriendGameInfo,
	kGameServerFriendGameStop,
	kGameServerQueryUserCurrentFriendGameInfo,
	kGameServerUserTipOff,
	kGameServerGetNewUserBenefit,
	kGameServerQueryUserTournamentFinalResult,
	kGameServerGetUserTournamentReward,
	kGameServerServerTimerStartNotify,
	kGameServerServerTimerStopNotify,
	kGameServerQueryNewUserBenefitStatus,

	kGameServerTournamentFixedTimeGradePlacingInfoNotify,
	kGameServerTournamentFixedTimeGradeResult,
	kGameServerTournamentFixedTimeGradeFinalResult,
	kGameServerGetServerCurrentTimestamp,

	kRequestIWantToJoin,
	kResponseIWantToJoin,
	kRequestHaveJoinMe,
	kResponseHaveJoinMe,
	kRequestOtherHongbao,
	kResponseOtherHongbao,

	kGameServerGetTournamentHistoryPlacing,
	kGameServerGetTournamentLeftValidTime,
	kGameServerTVGameCommand,
	kGameServerTVGameNumberNotify,


	kClientYanZhenMaRequest1,
	kServerYanZhenMaResponse1,
	kClientSendHongBaoRequest1,
	kServerSendHongBaoResponse1,
    kClientBindListRequest1,
    kServerBindListResponse1,

	kClientRequestAAward,
	kServerResponseAAward,
	kClientRequestListShiMin,
	kServerResponseListShiMin,
	kClientRequestJoinShiMin,
	kServerResponseJoinShiMin,

	kGameServerResetWinRate,
	kGameServerQueryWinRate,


	kGongHuiIHaveJoinRequest,
	kMemberMsgAmIRequest,
	kCreateGongHuiRequest,
	kModifyGongHuiRequest,
	kModifyMemberRequest,
	kApplyGongHuiRequest,
	kTickoutGongHuiRequest,
	kZhuangGongHuiRequest,
	kDismissGongHuiRequest,
	kHuiZhangApplyGongHuiRequest,
	kHuiZhangAnswerApplyGongHuiRequest,
	kListIHaveApplyGongHuiRequest,
	kListTuiJianGongHuiRequest,
	kListPaiMingGongHuiRequest,
	kListSearchGongHuiRequest,
	kListMemberRequest,
	kTaskRequest,
	kBenefitsRequest,
	kBenefitsExchageRequest,
	kLeaveGongHuiRequest,
	kLogNotify,
	kCancelApplyGongHuiRequest,
	
	kTophouse,
	kTopsome,

	kGameServerQueryUserLoginHistory,
	kGameServerClientPopUpNotify,
	kGameServerPreApplyTournament,
	kGameServerExitPreApplyTournament,

    kIOSMessagePush,
    kANDROIDMessagePush,

	kGameServerQuerySpecialSingleGameInfo,
	kGameServerUpdateRushLevelInfo,
	kGameServerEnterRushLevelRequest,
	kGameServerEnterRushLevelResponse,
	kGameServerUserFeedback,

	kGameServerTVGameStart,
	
    kGameServerExchangeRealHuaFeiRequest1,
	kGameServerExchangeRealBodyRequest1,
	kGameServerExchangeRealResponse1,

 	kClientYanZhenMaRequest2,
	kServerYanZhenMaResponse2,
	kClientSendHongBaoRequest2,
	kServerSendHongBaoResponse2,
    kClientBindListRequest2,
    kServerBindListResponse2,
	kClientHongBaoListRequest2,
    kServerHongBaoListResponse2,

	kClientYanZhenMaRequest3,
	kServerYanZhenMaResponse3,
	kClientSendHongBaoRequest3,
	kServerSendHongBaoResponse3,
    kClientBindListRequest3,
    kServerBindListResponse3,
	kClientHongBaoListRequest3,
    kServerHongBaoListResponse3,

	kGetFuShiCardListRequest = 20432,
	kGetFuShiCardListResponse,
	kAddFuShiCardRequest,
	kAddFuShiCardResponse,
	kModifyFuShiCardRequest,
	kModifyFuShiCardResponse,
	kRemoveFuShiCardRequest,
	kRemoveFuShiCardResponse,
	kGetFuShiCardGameNumListRequest,
	kGetFuShiCardGameNumListResponse,
	kGiveFuShiCardToGameRequest,
	kGiveFuShiCardToGameResponse,
	kFuShiCardTeamStatNotify,

	kGameServerQueryAllMail,
	kGameServerGetMailReward,
	kGameServerSendSystemMail,
	
	kGameServerRewardItem,
	kGameServerGetAllTVTournamentRoom,
	kGameServerGetTVTournamentRoomConfig,

	kGameServerQueryUserTableData,

	kRequestddHongbao,

	kGameServerCreateCustomMatch,
	kGameServerSearchCustomMatch,
	kGameServerEnterCustomMatch,
	kGameServerExitCustomMatch,
	kGameServerControlCustomMatch,
	kGameServerCustomMatchStatusNotify,
	
	kGameServerGetAccountBindMobile,
	kGameServerResetPasswordByAccount,
	kGameServerCheckAccountExists,
	kGameServerGetVerificationCodeByAccount,
	
	kGameServerQueryCustomMatchRecord,
	kGameServerQueryCustomMatchHistoryPlacing,

	kGameServerQueryRankingMatchInfo,
	kGameServerEnterMatch,
	kGameServerExitMatch,
	kGameServerPlayMatch,
	kGameServerMatchSpecialAction,
	kGameServerMatchSpecialNotify,

	kGameServerQueryRankingList,
	kGameServerQueryGlobalRankingList,
	kGameServerQueryLobbyRankingListGeneralInfo,
	kGameServerQueryRankingListRewardInfo,

	kGameServerQueryCommonRewardInfo,
	kGameServerGetCommonReward,

	kGameServerGetAdvertReward,
	kGameServerQueryLeftTimeToReadAdvert,
	kQueryGamePlayingStatus,
	kQueryGamePlayingStatusResponse,

	kGameServerQueryAIChallengeMatchInfo,
	kGameServerQueryUserAchievementInfo,
	kGameServerGetUserAchievementReward,
	kGameServerQueryRankingMatchSeasonRewardInfo,
	
	kGameServerGetUserInvitedReward,
	kGameServerUserInvitedNotify,
	kGameServerQueryUserInviteList,
	kGameServerGetUserInviteReward,

    kGameHongbaoExchangeHuafei,
    kGameHongbaoExchangeHuafeiResponse,
	
	kGameServerCancelPlayMatch,
	kGameServerQueryNewUserLoginRewardStatus,
	kGameServerGetNewUserLoginReward,

	kGameServerRoomCommonData,
	kGameServerExchangeJingDongGiftCard,
	kGameServerQueryOtherUserTableData,
	kGameServerQueryTodayCustomMatch,
	kGameServerQueryCustomMatchTableInfoRequest,
	
	kGameServerQueryUserActivityInfo,
	kGameServerGetUserActivityMissionReward,
	kGameServerGetUserActivityReward,
	kGameServerQueryUserContinuousLoginRewardStatus,
	kGameServerGetUserContinuousLoginReward,
	kGameServerGetUserGroupShareRewardStatus,
	kGameServerUpdateUserGroupShareCount,
	kGameServerGetUserGroupShareReward,
	kGameServerGetUserCommonShareRewardStatus,
	kGameServerGetUserCommonShareReward,
	kGameServerGetUserShareRewardStatus,
	kGameServerGetUserShareReward,

	kGameServerGetUserActivityCoin,
	kGameServerGetUserActivityCoinMissionInfo,
	kGameServerGetUserActivityCoinMissionReward,
	kGameServerPlayActivityCoinRoulette,
	kGameServerQueryActivityCoinRouletteNotice,
	kGameServerQueryActivityCoinRouletteRecord,
	kGameServerQueryActivityConfig,
	kGameServerUpdateUserWinScoreRecord,
	kGameSearchPrivateTable,



	//意见反馈 通过代理与华哥交互
	kClientDispatchUserFeedBackRequest,
	kClientDispatchUserFeedBackResponse,

	kClientDispatchFeedBackAgain,

	kClientDispatchFeedBackListRequest,
	kClientDispatchFeedBackListResponse,

	kClientDispatchGetOneQuestionRecordRequest,
	kClientDispatchGetOneQuestionRecordResponse,
	kGameRefreshTexasTable,

	kClientRequestStaticsPicture,
	kClientResponseStaticsPicture,
	kVerificationUserUrl,

	kGameServerQueryUserHeadFrameList,
	kGameServerQueryUserHeadFrameInUse,
	kGameServerSetUserHeadFrameInUse,

	kGameServerGetTaskTypeActivityInfo,
	kGameServerGetActivityTaskReward,
	kClientAgentRecordEventInfo,

	kGameServerQueryActivityCoinRouletteConfig,

	kfishaloneadjust,
	kGameSearchGetExchangeCodeRewardRequest,
	kGameSearchGetExchangeCodeRewardResponse,

	kGameServerQueryUserInviteMissionInfo,
	kGameServerGetUserInviteMissionReward,
	
	kGameServerDealerAnimationEmotionRequest,
	kGameServerDealerAnimationEmotionResponse,
	kGameServerDealerRewardRequest,
	kGameServerDealerRewardResponse,

	kGameServerQueryUserEquipmentInfo,
	kGameServerQueryUserEquipmentInUse,
	kGameServerSetUserEquipmentInUse,
	kGameServerQueryEquipmentExchangeProductInfo,
	kGameServerExchangeEquipment,
	
	kGameServerUserInviteMissionProgressUpdateNotify,
	kGameServerQueryUserExchangeItemProductInfo,
	kGameServerExchangeItem,
	kGameServerQueryUserBuyProduct,
	kGameServerQueryFanFanLeConfig,
	kGameServerFanFanLeRequest,
	kGameServerFanFanLeResponse,
	kGameServerQueryUserOnlineRewardInfo,
	kGameServerGetOnlineReward,

	kGameServerQueryDrawCardActivityInfo,//查询翻牌活动数据
	kGameServerDrawCard,//翻牌
	kGameServerQueryDrawCardRewardPoolInfo,//查询翻牌活动奖池
	kGameServerQueryDrawCardRewardRecord,//查询翻牌奖励记录
	kGameServerQueryDrawCardRewardNotice,//查询翻牌大奖公告

	kGameServerItemChangeNotify,//道具变化,服务器主动往下通知

	kGameServerQueryUserReplayRecordRequest,//查询玩家所有对局记录
	kGameServerQueryReplayInfoRequest,//查询玩家一局记录的详细信息
	kGameServerQueryReplayDataRequest,//请求播放数据

	kGameServerQueryProductInfoRequest,//请求礼包数据
	
	kGameServerQueryProductInfoResponse,

	kGameServerGuestRegistSdkAccount,//游客转正第三方sdk

	kGameServerQueryUserBackMissionInfo,//回归用户七天任务,
	kGameServerGetUserBackMissionReward,

	kGameServerInviteUserRegisterGame,//邀请好友注册游戏
	kGameServerQueryInviteUserRegisterInfo,//获取邀请好友注册信息

	kGameServerGenerateSdkToken,//请求生成token供接入sdk的应用使用

	kGameServerQueryRoomConfigByGameType,//根据game type获取房间配置
	kGameServerQueryRoomStatusByGameType,//根据game type获取房间人数等状态

	kGameServerGetSceneRewardRequest,	//用于用户从不同场景登录的奖励(暂时只有象棋有)
	kGameServerGetSceneRewardResponse,

	kGameServerPrepareWantPlayGame,//预约玩法功能
	kGameServerClientEventTrack,//客户端打点(经过游戏服务器以便填充一些附加的数据)

	kGameServerGetUserTwoStageShareFirstReward,//二段分享领第一段奖励
	kGameServerGetUserTwoStageShareSecondReward,//二段分享领第二段奖励

	kGameServerQueryActivityRewardPoolRank,//查询排行榜(翻牌奖池)
	kGameServerUserPlayBroadcastRequest, // 玩家使用系统喇叭
	kGameServerUserPlayBroadcastResponse,

	kGameServerGetCritAdvertReward,//暴击广告领奖
	kGameServerQueryUserLobbyAchievementInfo,//获取大厅成就信息
	kGameServerGetUserLobbyAchievementReward,//获取大厅成就奖励
	kGameServerUpdateGeneralWelfareProgress,//更新全民福利进度
	kGameServerQueryGeneralWelfareInfo,//获取全民福利信息
	kGameServerGetGeneralWelfareReward,//领取全民福利奖励
	kGameServerQueryNewUserLoginRewardStatusV2,//获取迎新豪礼状态
	kGameServerGetNewUserLoginRewardV2,//领取迎新豪礼奖励

	kGameServerQueryAircraftParam, //捕鱼飞机
	//邀请树
	kGameServerQueryTreeInfo,
	kGameServerEnterTreeCode,
	kGameServerGetTreeReward,
	kGameServerTreeFriendOperator,
	//离线奖励
	kGameServerGetOfflineRewardRequest,//用于领奖
	kGameServerGetOfflineRewardResponse,
	kGameServerQueryOfflineRewardInfoRequest,//用于查询信息
	kGameServerQueryOfflineRewardInfoResponse,
	//实名认证
	kGameServerRealNameVerify,
	//回归邀请
	kGameServerQueryBackInviteInfo,//查询回归邀请信息
	kGameServerAbandonBackInvitedUser,//放弃回归邀请玩家
    kGameServerGetBackInviteMissionReward,//获取回归邀请奖励
	//二段分享
	kGameServerQueryUserShareFirstRewardStatus,//查询第一段奖励的状态
	//幸运翻翻乐活动
	KGameServerQueryDrawDrawHappyActivityConfigInfo,//查询幸运翻翻乐活动底分和倍率和各奖励对应的奖励数
	KGameServerLuckyDrawDrawHappyStartGame,		//幸运翻翻乐活动开始游戏
	KGameServerQueryDrawDrawHappyRewardPoolInfo,//查询幸运翻翻乐活动奖池
	KGameServerQueryDrawDrawHappyRewardRecord, //查询幸运翻翻乐奖励记录
	KGameServerQueryDrawDrawHappyRewardNotice, //查询幸运翻翻乐大奖公告

	kGameServerQueryUserTrialGameRewardStatus,//查询试玩游戏奖励状态
	kGameServerTrialGame,//通知试玩游戏成功
	kGameServerGetUserTrialGameReward,//领取试玩游戏奖励
	kGameServerGetTreeRecord,//获取树信息记录

	kGameServerGenerateTwoStageShareRewardToken,//生成二段奖励token

	//state server
	kGameServerStateServerAdWallStatus,//获取广告墙状态
	kGameServerStateServerModuleUpdateInfo,//模块更新信息
	kGameServerStateServerPackageUpdateInfo,//整包更新信息
	kGameServerStateServerUpdateInfo,//获取以上所有状态信息
	kGameServerThumbUp,//点赞
	kGameServerGetReward,//获奖的公共消息,agent会统一广播桌子(如果在桌内的话)
	kGameServerTestDataServer,//客户端测试打点数据

	//游戏订阅
	KGameServerSubScribeMessageConfig,
	KGameServerUserSubscribeMessage,
	KGameServerSubScribeMessageConfigScript, //脚本查询对应配置
	KGameServerQuerySubScribeReward,		 //玩家查询获得奖励

	kGameServerQueryGuessInGameRecord,//获取竞猜记录
	kGameServerPlayXiaoYouXiRoulette,//小游戏大转盘
	kGameServerGetShopInfo,//获取商城信息
	kGameServerQueryXiaoYouXiRouletteConfig,//查询小游戏大转盘配置
	kGameServerStateServerGetNoticeInfo,//状态服务器，获取公告信息

	kGameServerQueryForbidShopID,//客户端充值后获取禁掉的商品列表

	kGameServerFriendGameTaskInfo,//查询好友房间任务信息
	kGameServerGetFriendGameTaskReward,//请求领取好友房间任务奖励
	kGameServerReplenishContinuousLoginReward, //印尼连续登陆补签

	kGameServerEnterTournament,//进比赛场查询个人数据
	
	kGameServerFestivalHeadFrameInfo,//查询节日头像框信息
	kGameServerFestivalHeadFrameReward,//请求头像框奖励
	kGameServerPostUserPositionInfo,//上传用户位置信息
	kGameServerQueryUserRechargeInfo,

	//十全十美活动
	kGameServerQuerySlyderAdventuresActivityInfo,
	kGameServerSlyderAdventuresStartGame,
	
	//泰国随机礼包
	kGameServerQueryRandomGiftBagInfo,
	//傍晚礼包
	kGameServerQueryTrunkGiftBagInfo,

	//新手七日礼包
	kGameServerQueryNewUserWeekTaskInfo,//查询信息
	kGameServerUpdateSingleNewUserWeekTaskProgress,//更新子任务进度
	kGameServerGetSingleNewUserWeekTaskReward,//请求子任务奖励
	kGameServerGetNewUserWeekTaskReward,//请求整体任务奖励

	//查询十全十美活动和充值有礼活动开启状态
	kGameServerQueryActivityOpenStatus,

	//节日任务
	kGameServerQueryFestivalTaskInfo,//查询信息
	kGameServerGetFestivalReward,//请求奖励

	//循环任务
	kGameServerQueryCycleTaskInfo,//查询信息
	kGameServerGetCycleReward,//请求奖励
	
	//获取傍晚礼包免费的奖励
	kGameServerGetFreeTrunkGiftBagReward,

	
	//领取泰国宣传图奖励
	kGameServerGetPromotionalImageReward,
	//首充礼包
	kGameServerGetFirstRechargReward ,

	
	kGameServerQueryUserWeekSignInStatus = 20662, // 查询周签到信息
	kGameServerGetUserWeekSignInReward = 20663, // 领取周签到奖励
	kGameServerGetUserWeekSignInOldReward = 20664, // 领取周签到补签奖励
	kGameServerGetUserWeekSignInFinalReward = 20665, // 领取周签到累计奖励
	
	kGameServerDrawTaskConfig = 20671,	//获取抽奖配置信息
	kGameServerDrawTaskInfo = 20672,//查询抽奖房间任务信息
	kGameServerGetDrawTaskReward = 20673,//请求领取抽奖任务房间任务奖励
	kGameServerQueryUserGameGradeRequest = 20681,   //请求玩家战绩信息
	kGameServerQueryBaiRenGameRewardPool = 20682, //查百人游戏奖池

	kGameServerBindEmailCodeRequest = 20690,			//绑定邮箱验证码
	kGameServerBindEmailRequest = 20691,			//绑定邮箱
	kGameServerBindEmailResponse = 20692,			//请求绑定邮箱 和 验证码 的返回

	//高级场玩牌活动
	kGameServerQueryExchangeShopInfo = 20693, //请求商城配置 
	kGameServerQueryExchangeRecord = 20694, //请求兑换记录
	kGameServerExchangeShop = 20695, //商城兑换

	kGameServerQueryUserUpperSeniorAvitivty = 20696, //请求活动数据
	kGameServerQueryUserUpperSeniorWinPrizeList = 20697, //请求中奖榜单
	kGameServerUpperSeniorNotifyUserGetPrize = 20698, //通知玩家中奖
	

		

	// 组队相关消息处理
    kGameServerTeamMode       = 20700,
    kGameServerTeamModeCreateTeam,          // 创建队伍
    kGameServerTeamModeSelectRoom,          // 选择房间
    kGameServerTeamModeJoinTeam,            // 加入队伍
    kGameServerTeamModeQuitTeam,            // 退出队伍
	kGameServerTeamModePreStartMatch,       // 开始匹配
	kGameServerTeamModeMatchResult,         // 匹配结果
	kGameServerTeamModeQuitMatch,           // 退出匹配
	kGameServerTeamModeReturnTeam,          // 返回小队
	kGameServerTeamModeChat,                // 聊天消息
	kGameServerTeamModeUpdateTeamInfo,      // 更新队伍信息
	kGameServerTeamModeUpdateUserStatus,    // 玩家准备/取消准备
	kGameServerTeamModeTaskInfo,			// 查询信息
	kGameServerTeamModeReward,				// 请求奖励
	kGameServerTeamModeStartMatch, 		    // 开始匹配
	kGameServerTeamModeKickUser, 		    // 踢出玩家 20715
    kGameServerTeamModeEnd = 20720, 		// 预留协议号	

	//新新手七日礼包
	kGameServerQueryNewUserWeekTaskInfoPlus = 20721,//查询信息
	kGameServerUpdateSingleNewUserWeekTaskProgressPlus = 20722,//更新子任务进度
	kGameServerGetSingleNewUserWeekTaskRewardPlus = 20723,//请求子任务奖励
	kGameServerGetNewUserWeekTaskRewardPlus = 20724,//请求整体任务奖励
	kGameServerGetNewUserSignRewardPlus = 20725,    //请求签到奖励
	
	//走马灯通知
	kGameServerHorseRaceLampNotify,

	// 打大a 那达慕活动
	kGameServerQueryNaadamTaskInfo = 20727,			//查询那达慕信息 （活动信息，房间配置等）
	kGameServerQueryNaadamTaskUserInfo = 20728,		//查询那达慕个人信息
	kGameServerGetNaadamReward = 20729,				//请求奖励
	// 打大a 视频活动
	kGameServerQueryVideoTaskInfo = 20730,			//查询信息 （活动信息，房间配置等）
	kGameServerQueryFinishVideoTaskInfo = 20731,	//完成任务（看视频了）
	kGameServerGetVideoReward = 20732,				//请求奖励

	kGameServerRankMatchTeamModeOpRequest=20740,	//排位赛组队玩法请求
	kGameServerRankMatchTeamModeOpResponse=20741,     //排位赛组队玩法回复
	kGameServerRankMatchTeamModeUpdateTeamInfo = 20742, //更新组队消息
	kGameServerRankMatchTeamModeMatchResult =20743, //匹配结果
	kGameServerRankMatchTeamModeMessage= 20745,  //组队聊天     
	kGameServerRankMatchTeamModeEnd= 20749,		//给排位赛组队预留协议


	kGameServerQueryUserFriendMultipleGameInfo = 20750, //查询多个好友游戏战绩

	kGameServerGetGameSeverReward = 20801,				//请求gamesever奖励

	kGameServerQueryDDZAllowanceConfig = 20790,//斗地主补助金配置
	kGameServerAllowanceDataRsp = 20791,//斗地主补助返回
	kGameServerAllowanceRecieveAaward = 20792,//斗地主补助金领取
	// 母亲节活动
	kGameServerQueryActivityInfoEx = 21000, //c-m-a a-m-c 获取活动信息
	kGameServerActivityOperEx = 21001, //c-m-a a-m-c 获取活动信息

	//dispatch与midlayer
    kDispatchMidlayerQueryAllBroadcastReq = 30001,
    kDispatchMidlayerQueryAllBroadcastRsp = 30002,
    kDispatchMidlayerMax = 35000,
	
	//街机厅
	kVideoArcadeCommondBegin = 37000,
	kVideoArcadeRoleNodeBasicInfoRes,
	kVideoArcadeQueryUserFullInfo,
	kVideoArcadeLobbyExtraInfoRes,
	kVideoArcadeDisconnectRoomRes,
	kVideoArcadeKickOutRes,
	kVideoArcadeUsePropReqRes,
	kVideoArcadeLogicBeatHeartRes,
	
	kVideoArcadeFruitMachineStartReqRes = 37100,
	kVideoArcadeFruitMachineCompareReqRes,

	kVideoArcadeTreasureHuntStartReqRes = 37150,

	kVideoArcadeSlotsStartReqRes = 37180,
	kVideoArcadeSlotsFreeStartReqRes,
	kVideoArcadeSlotsCardGameStartReqRes,

	//fish server
	kFishServerQueryUserBasicFishInfo = 40000,
	kFishServerModifyUserBasicFishInfo,
	//新玩家进入通知
	kFishServerNewPlayerEnterNotice,
	//玩家离开通知
	kFishServerRoleNodeLeaveNotice,
	//玩家技能信息
	kFishServerSkillInfoNotice,
	//新玩家进入关卡信息通知
	kFishServerNowTollgateinfoNotice,
	//休渔期
	kFishServerChangeTollgateNotice,
	//当前存在鱼信息
	kFishServerNowTollgateFishInfoNotice,
	//玩家发射子弹请求
	kFishServerRoleNodeShotReq,
	kFishServerRoleNodeShotRes,
	kFishServerRoleNodeShotFailedRes,

	//打中鱼请求回应
	kFishServerRoleNodeShotNetReqRes,
	//切换倍率
	kFishServerChangeBetReqRes,
	//使用技能
	kFishServerUseSkillReqRes,
	//玩家锁定状态出现
	kFishServerLockStatusAppear,
	//关卡冰冻状态
	kFishServerFreezeTollgateRes,
	KFishServerFrameSynReqRes,
	//升级炮台
	kFishServerUpgradeBetIndexReqRes,
	
	kFishServerAnimationEmotionReqRes,
	kFishServerExpressionReqRes,
	
	kFishServerRoomStatus,
	kFishServerEnterLobby,
	kFishServerRoomDisconnected,
	kFishServerLobbyDisconnected,

	kFishServerUsePropReqRes,

	//测试消息
	kFishServerModifyReqRes,
	kFishServerUserFeedback,
	kFishServerKickOutRes,
	kFishServerLogout,
	kFishServerLogicInitInfoOverRes,
	kFishServerOffline,
	kFishServerOffline2Online,
	kFishServerGameExtraInfoRes,
	kFishServerPlayLotteryReqRes,
	kFishServerItemChangeNotify,

	//激光卡 击中鱼请求回应
	kFishServerChangeToCardLaserStatusReqRes,
	kFishServerCardLaserShotFishReqRes,
	kFishServerCardLaserShotNetFishReqRes,
	
	kFishServerChangeToCardBombStatusReqRes,
	kFishServerCardBombShotFishReqRes,
	kFishServerCardBombShotNetFishReqRes,
	
	kFishServerChangeToCardDoubleShotStatusReqRes,
	kFishServerCardDoubleShotReqRes,
	kFishServerCardDoubleShotNetReqRes,

	//捕鱼任务
	kFishServerIssueMissionNotify,
	kFishServerMissionCompleteReqRes,
	kFishServerFlopGameReqRes,
	kFishServerStartRedPacketsNotify,
	kFishServerChargeRedPacketsReqRes,

	//Fishing Tournament
	kFishServerTournametInfoRes,
	kFishServerTournamentStartRes,
	kFishServerTournametShotReq,
	kFishServerTournamentShotNetReq,
	kFishServerTournamentClientFinishedReq,
	kFishServerTournamentOverNotify,
	kFishServerBlockedInfoRes,
	kFishServerTournamentCurrentInfoRes,
	kFishServerTournamentClientReadyReq,
	kFishServerTournamentGiveUpRes,
	kFishServerTournamentClientTimeOverReq,
	
	//好友
	kFishServerQueryPrivateRoomStatus,
	kFishServerQueryPrivateRoomNodeStatus,
	kFishServerEnterPrivateTable,

	kFishServerDailyMissionInfoNotify,
	kFishServerLobbyRefreshDailyMissionReqRes,
	kFishServerLobbyDailyMissionCompleteReqRes,
	kFishServerGameRefreshDailyMissionReqRes,
	kFishServerGameDailyMissionCompleteReqres,

	kFishServerClientReadyReq,

	kFishServerRoleNodeShotBossReqRes,
	kFishServerBossGameInfoRes,
	kFishServerMoneyPoolInfoReqRes,
	kFishServerDragonBallGameReqRes,
	
	kFishServerFishingItemInfoNotify,
	kFishServerNewGuideRes,

	//客户端请求大奖赛信息
	kFishServerGrandPrixInfoReqRes,
	kFishServerGrandPrixRankdingInfoReqRes,

	kFishSeverGrandPrixInfo2ReqRes,
	kFishServerGrandPrixRankdingInfo2ReqRes,

	kFishServerRoleNodeShotNetRedPacketFishReqRes,
	kFishServerTournamentHistoryPlacingInfoReqRes,

	kFishServerLobbyUsePropReqRes,

	//捕鱼彩票 
	kFishServerClientQueryLotteryPoolReq,
	kFishServerClientQueryOpenPoolInfoReqRes,
	kFishServerClientQueryLotteryExtraInfoReqRes,

	kFishLogicServerUnlockPetRequestRes,
	kFishLogicServerEquipPetRequestRes,
	kFishLogicServerUpgradePetReqRes,

	kFishLogicServerPetSkillReadyShotReqRes,
	kFishLogicServerPetSkillShotNetReqRes,

	kFishLogicClientQueryPetInfoReqRes,
	kFishLogicClientQueryNoticeInfoReqRes,

	kFishLogicServerPetSkillShotReqRes,

	//号角召唤鱼
	kFishLogicServerCallFishAppearRes,
	//摇钱树领奖
	kFishLogicServerGetMoneyTreeRewardReqRes,
	//请求登录奖励 废弃
	kFishLogicServerGetLoginRewardReqRes,
	//请求神秘
	kFishLogicGetFishingShopInfoReqRes,
	//购买/卖
	kFishLogicFishShopBuyOrSellItemReqRes,

	kFishLogicClientQueryPetRankingReqRes,
	kFishLogicClientQueryTreasureMapInfoReqRes,
	//Logic主动通知客户端藏宝图信息
	kFishLogicClientTreasureMapInfoNotice,
	kFishLogicClientTreasureStartReq,
	kFishLogicClientOpenTreasureMapCellReqRes,
	kFishLogicClientExchangeItemReqRes,

	//兑换商城
	kFishLogicClientExchangeShopReqRes,
	//购买每日礼包
	kFishLogicClientBuyDailyGiftBagReqRes,
	//在线奖励礼包
	kFishLogicClientGetOnlineGiftReqRes,
	//特惠礼包
	kFishLogicClientBuyPreferentialGiftBagReqRes,
	//房间内兑换
	kFishLogicClientRoomExchangeItemReqRes,
	//普通礼包
	kFishLogicClientBuyNormalGiftBagReqRes,
	//请求领取新手任务奖励
	kFishLogicClientGetNewPlayerMissionRewardReqRes,
	//领取7日登陆奖励(大厅)
	kFishLogicClientGet7LoginGiftReqRes,
	
	//领取明日礼包
	kFishLogicClientGetTomorrowGiftReqRes,
	//新手礼包
	kFishLogicClientGetNewPlayerGiftBagReqRes,
	//客户端请求配置
	kFishServerClientQueryClientConfReqRes,
	kFishServerClientTreasureMapOpenAllCellsRes,
	//房间内特惠礼包
	kFishLogicClientRoomBuyPreferentialGiftBagReqRes,
	//占卜
	kFishClientLobbyDivinationReqRes,
	kFishClientLobbyQueryDivinationMarqueeReqRes,
	//Boss开奖跑马灯
	kFishClientLogicQueryBossBulletinReqRes,
	//房间内7日登陆奖励(房间的)
	kFishClientLogicRoomGet7LoginGiftReqRes,
	kFishingLobbyLogicAddFishingItemsRes,
	//签到
	kFishingClientLobbySignReqRes,
	//房间内领取活跃度
	kFishingClientLogicGetActivityReqRes,
	//房间内领取活跃度奖励
	kFishingClientLogicGetActivityRewardReqRes,
	//大厅领取活跃度
	kFishingClientLobbyGetActivityReqRes,
	//大厅领取活跃度奖励
	kFishingClientLobbyGetActivityRewardReqRes,
	//房间内每日可买一次的礼包
	kFishingClientLogicBuyOneDayBagReqRes,
	kFishingClientLobbyGetCashingCodeReqRes,
	kFishingClientLobbyGetTournamentAdsReqRes,
	kFishingClientLobbyGetStartGameGiftReqRes,
	kFishingClientLogicChangePetReqRes,
	kFishingClientLogicGetThirdMoneyRewardReqRes,
	kFishingClientLogicGetYiZhuanFanPanReqRes,
	kFishingClientBuyVIPReqRes,
	kFishingClientBuyVIP2ReqRes,
	kFishingClientLogicPlayFishTycoonReqRes,
	kFishingClientLobbyWishingWellReqRes,
	kFishingClientLobbyDrawPayReturnRewardReqRes,
	kFishingClientLobbyDrawBaoShenSongLiReqRes,
	kFishingClientLogicFishingReqRes,
	kFishingClientLogicWishingWellReqRes,
	kFishingClientLobbyBuyActivityGiftBagReqRes,
	kFishingClientLobbyGetXianJieBaoZangActivityRewardReqRes,
	kFishingClientLobbyGetShenLongJiangShiActivityRewardReqRes,
	kFishingClientLobbyLeiChongYouLiActivityRewardReqRes,
	kFishingClientLobbyZaJinDanActivityRewardReqRes,
	kFishingClientLeaveLobbyReqRes,
	kFishingClientLobbyGetLoginDailyPayRewardReqRes,
	kFishingClientLogicNewGuideRes2,
	kFishingClientLogicGetPovertyReward,
	kFishingClientLobbyFunc1000SinginReqRes,
	kFishingClientLobbyFunc1000SinginRewardReqRes,
	kFishingClientLobbyFunc1001PlayReqRes,
	kFishingClientLobbyFunc1002RewardReqRes,
	kFishingClientFunc1005GetRewardReqRes,
	kFishingClinetPlayScoreWinRewardReqRes,
	kFishingClientFunc1005UnlockSeniorReqRes,
	kFishingClientFunc1006PayReturnReqRes,
	kFishServerKilledFishCntListRes,
	kFishServerCannonGiftBagInfo = 40160,
	// 领取7日总积分奖励(大厅) [6/29/2020 10:56:23 Kira]
	kFishLogicClientGet7LoginActivityGiftReqRes,
	// 7日总积分领取(房间内) [6/29/2020 10:31:21 Kira]
	kFishClientLogicRoomGet7LoginActivityGiftReqRes,

	// 单比支付 [6/30/2020 10:27:15 Kira]
	kFishServerOncePayNotify,
	//购买7日礼包(lobby)
	kFish7DayClientBuyGiftBagReqRes,

	kFishingClientRankRewardListReqRes,
	kFishingClientGetRankRewardReqRes,
	kFishingClientGetExtraInfoReqRes,

	

	kFishAircraftBasicInfoRes = 42000,
	kFishAircraftUpgradeReqRes,
	kFishAircraftSurviveDataInfoRes,
	kFishAircraftSurvivePassReqRes,

	//fish lobby logic
	kFishLobbyServerExtraInfoRes = 43000,
	kFishLobbyServerPlayLotteryReqRes,
	kFishAgentAskLobbyClearUserLoginInfoReq,
	kFishAgentLobbyUserSceneChangeRes,
	kFishAgentLogicUserKeepAliveReqRes,
	kFishLobbyServerAttributionReport,
	kFishLobbyAgentEnterLobbyResponse,
	kFishFishingServerKickoutFinishGameReqRes,
	kFishLobbyServerRoomInfoRes,

	//fish logic/agent
	kFishLogicServerAttributionReport = 44000,
	kFishLogicServerUpdateFishBasicUserInfo,
	kFishLogicServerQueryUserControlInfo,
	kFishLogicServerUpdateUserControlInfo,
	kFishLogicServerQueryUserRoleNodeSkillInfo,
	kFishLogicServerUpdateUserRoleNodeSkillInfo,
	kFishLogicServerAllConnectionEstablishedNotify,
	kFishLogicServerDropItemRecord,
	kFishLogicServerMoneyRecord,
	kFishLogicServerConnectAgentResult,
	kFishAgentServerQueryRoomStatus,
	kFishAgentServerModifyRoomStatus,
	kFishLogicServerGameRecord,
	kFishLogicServerSkillRecord,
	kFishLogicServerUpgradeGunRecord,
	kFishLogicServerAnimationEmotionRecord,
	kFishLogicServerQueryUserRoomExtraInfo,
	kFishLogicServerQueryUserFullFishInfo,
	kFishLogicServerTournamentRoomStatusNotify,
	kFishLogicServerNormalRoomStatusNotify,
	kFishLogicServerPrivateRoomStatusNotify,
	kFishLogicServerQueryUserAllRoomExtraInfo,
	kFishLogicServerQueryUserDailyMission,
	kFishLogicServerUpdateUserDailyMission,
	kFishLogicServerQueryRoomGlobalConfig,
	kFishLogicServerUpdateRoomGlobalConfig,
	kFishLogicServerOffline2OnlineEnterRoomResponse,
	kFishLogicServerQueryUserHistoryReward,
	kFishLogicServerUpdateUserHistoryReward,
	kFishLogicServerKickoutUserReq,
	kFishLogicServerQueryUserFishItem,
	kFishLogicServerUpdateUserFishItem,
	kFishLogicServerUpdateUserTournamentRoomApplyInfo,
	kFishLogicServerQueryLotteryPool,
	kFishLogicServerUpdateLotteryPool,
	kFishLogicServerLotteryGenerateNewNumber,
	kFishLogicServerQueryLotteryOpenInfo,
	kFishLogicServerLotteryOpenReward,
	kFishLogicServerQueryLotteryRecord,
	kFishLogicServerInsertLotteryRecord,
	kFishLogicServerGetLotteryReward,
	kFishLogicServerQueryUserPetInfo,
	kFishLogicServerUpdateUserPetInfo,
	kFishLogicServerNotifyFishGameFinish,
	//fish rank
	kFishRankClientStatusInfo,
	kFishRankQueryRequest,
	kFishRankQueryResponse,
	kFishRankUserQueryRequest,
	kFishRankUserQueryResponse,
	//fish rank
	kFishLogicServerUpdateTreasureMapInfo,
	kFishLogicServerNewUserTask,
	kFishLogicServerRoomControlInfo,
	kFishLogicServerDropHistory,
	kFishLogicServerQueryUserNewDailyMission,
	kFishLogicServerQueryUserActivity,
	kFishLogicServerQueryUserPayRebateInfo,
	kFishBuyVipWithSecondMoney,
	kFishLogicServerNewUserTask2,
	kFishLogicServerQueryUser7DaysLoginMission,
	kFishLogicServerQueryActivityConfig,
	kFishLogicServerQueryHistoryScore,
	kFishLogicServerQueryUserMission,
	kFishLogicServerQueryUserExtraParam,
	kFishLogicServerQueryNewUserDailyPay,
	kFishLogicServerQueryUserRoomInfo,
	kFishLogicServerQueryUser7DaysActivityLoginMission,

	
	//管理命令字，45000-50000
	kGameServerDisconnectWithLoginServer = 45000,
	kGameServerQueryOnlineUserAmount = 45001,
	kGameServerSetBroadcast = 45002,
	kGameServerKickOnlineUser = 45003,
	kGameServerUseMasterDB = 45004,
	kGameServerUseSlaveDB = 45005,
    kSMCGameServerSwitchDispatchReq,
    kSMCGameServerSwitchDispatchRsp,
    kSMCLoginServerEnableGameServerReq,
    kSMCLoginServerEnableGameServerRsp,
	kSMCGameServerBaiRenResetControlInfo,
	kSMCGameServerQueryGeneralOnlineGameStatus,
	kMaxClientRoomServerMsg = 50000,
    
    //loginserver与gameserver之间交互的命令字，暂定50000<= && <=60000
	kGameServerReportSelfInfoToLoginServer           = 50001,
	kGameServerSendHeartBeatPackageToLoginServer,
	kLoginServerResponseHeartBeatPackageToGameServer,


	//poker agent and logic
	kPokerLogicServerConnectAgent = 51000,
	kPokerLogicServerNotifyRoomStatus,
	kPokerLogicServerNotifyUserEnterRoom,
	kPokerLogicServerNotifyUserLeaveRoom,
	kPokerLogicServerNotifyUserCountChanged,
	kPokerLogicServerUpdateServerAttribute,
	kPokerLogicServerClearUserAttentionTable,
	kPokerAgentServerFriendGameConfigNotify,
	kPokerAgentServerTeamModeGameConfigNotify,
	kPokerAgentServerTeamModeGameData,
	kPokerLogicServerNotifyUserCountGroupChanged,	// 人数组改变（组队玩法需求）



    kMaxLoginServerGameServerMsg                     = 60000,

    //server to DBProxy
	kServerDBProxyBootstrap       = 60001,
    kServerDBProxyScoreOperation,
	kServerDBProxyProxyIsOn,
	kServerDBProxyProxyIsOff,
	kServerDBProxyRewardScore,
	kServerDBProxyScoreOperationAdWall,
	kServerDBProxyScoreOperationIAP,
    kServerDBProxyScorePaySuccessNotify,
	kServerDBProxyAddOfflineMsg,
	kServerDBProxyAddOfflineFriendRequest,
	kGameServerMiddleServerGameResult,
	kGameServerMiddleServerAddFuncCard,
	kGameServerMiddleServerAddYuanBao,
    kGameServerMiddleServerTurnInfoReport,
    kGameServerMiddleServerFinishMission,
	kGameServerMiddleServerGameRecord,
	kGameServerMiddleServerTournamentGameRecord,
	kGameServerMiddleServerAddTVTournamentScore,
	kGameServerMiddleServerTVDetailGameRecord,
	kGameServerMiddleServerTournamentSingleGameRecord,
	kGameServerMiddleServerInsertTVAutoReplayRecord,
	kGameServerMiddleServerQueryTVAutoReplayRecord,
	kGameServerMiddleServerHttpPacket,//通过http传递packet过来
	kGameServerMiddleServerGameResultData,//游戏结束后的数据
    kMaxServerDBProxyMsg = 60100,

    //Midlayer to Gameserver
    kMidLayerGameServerSystemBroadcastNotify    = 60101,
    kMidLayerGameServerRegBroadcastConReq,
    kMidLayerGameServerRegBroadcastConRsp,
    kMidLayerGameServerAddOnceBroadcastReq,
    kMidLayerGameServerAddOnceBroadcastRsp,
    kMidLayerGameServerOnlineNumReporte,
	kMidLayerGameServerUserDisconnect,
	kMidLayerGameServerXiaoLaBaNotify,
    kMidLayerGameServerBroadcastNotify,
    kMidLayerGameServerQuerySpeakerConfigRequest,
    kMidLayerGameServerQuerySpeakerConfigResponse,
    kMidLayerGameServerQueryRoomInfoRequest,
    kMidLayerGameServerQueryRoomInfoResponse,
    kMidLayerGameServerQueryGameLengthRewardRequest,
    kMidLayerGameServerQueryGameLengthRewardResponse,
	kMidLayerGameServerQueryMissionConfigRequest,
	kMidLayerGameServerQueryMissionConfigResponse,
	kMidLayerGameServerMissionConfigChanged,
	kMidLayerGameServerQueryBaggageRequest,
	kMidLayerGameServerQueryBaggageResponse,
	kMidLayerGameServerAddBaggageItemRequest,
	kMidLayerGameServerAddBaggageItemResponse,
	kMidLayerGameServerConsumeBaggageItemRequest,
	kMidLayerGameServerConsumeBaggageItemResponse,
	kMidLayerGameServerUpgradeWeaponRequest,
	kMidLayerGameServerUpgradeWeaponResponse,
	kMidLayerGameServerUpdateExperience,
	kMidLayerGameServerUserGoodsReward,
	kMidLayerGameServerUpdateFishExp,
	kMidLayerGameServerUpdateFishLevel,
    kMidLayerGameServerUpdateFishPowerPool,
    kMidLayerGameServerQueryUserQuestRequest,
	kMidLayerGameServerQueryUserQuestResponse,
	kMidLayerGameServerUserCompleteQuestRequest,
	kMidLayerGameServerUserCompleteQuestResponse,
	kMidLayerGameServerUserUpdateQuestRequest,
	kMidLayerGameServerUserUpdateQuestResponse,
	kMidLayerGameServerOnlineGameStatusReport,
	kMidLayerGameServerAddUserCouponRequest,
	kMidLayerGameServerAddUserCouponResponse,
	kMidLayerGameServerGetFakeExchangeSuccUserRequest,//no use
	kMidLayerGameServerGetFakeExchangeSuccUserResponse,//no use
	kMidLayerGameServerGetFakeCouponNotifyRequest,
	kMidLayerGameServerGetFakeCouponNotifyResponse,
	kMidLayerGameServerAddUserTotalServiceFee,
	kMidLayerGameServerResetUserTotalServiceFee,
	kMidLayerGameServerAddScoreWinFromRobot,
	kMidLayerGameServerNotifyGameStart,
	kMidLayerGameServerNotifyGameStop,
	kMidLayerGameServerConnectToMidLayer,
	kMidLayerGameServerDisconnectToMidLayer,
	kMidLayerGameServerQueryCardPatternRequest,
	kMidLayerGameServerQueryCardPatternResponse,
	kMidLayerGameServerCardPatternAction,
	kMidLayerGameServerUpdateTournamentStat,
	kMidLayerGameServerAddUserHuaFeiQuan,
	kMidLayerGameServerNotifyPayContributionChange,
	kMidLayerGameServerQueryPayContributionConfig,
	kMidLayerGameServerNotifyPayBonusGameCountChange,
	kMidLayerGameServerQueryUserGameLotteryEnergy,
	kMidLayerGameServerUpdateUserGameLotteryEnergy,
	kMidLayerGameServerAddLotteryGameRecord,
	kMidLayerGameServerCopyOldWinLoseCountToGuanDan,
	kMidLayerGameServerAddUserTreasureBoxCount,
	kMidLayerGameServerEnterGame,
	kMidLayerGameServerQueryBaiRenGameConfig,
	kMidLayerGameServerUpdateBaiRenGameConfig,
	kMidLayerGameServerUpdateUserControlInfo,
	kMidLayerGameServerAddUserItem,
	kMidLayerGameServerQueryGrayUser,
	kMidLayerGameServerQueryUserControlInfo,
	kMidLayerGameServerUpdateUserRoomStat,
	kMidLayerGameServerAckMessage,
	kMidLayerGameServerReverseAckMessage,
	kMidLayerGameServerQueryTableRewardPool,
	kMidLayerGameServerUpdateTableRewardPool,
	kMidLayerGameServerInsertUserFriendGameInfo,
	kMidLayerGameServerDeleteUserFriendGameInfo,
	kMidLayerGameServerDispatchServerSupportGameServerReport,
	kMidLayerGameServerInsertUserTournamentFinalResult,
	kMidLayerGameServerUpdateUserFriendGameStat,
	kMidLayerGameServerInsertTournamentHistoryPlacing,
	kMidLayerGameServerClearTVGameRecord,
	kMidLayerGameServerNormalGameRecord,
	kMidLayerGameServerUpdateUserExpInfo,
	kMidLayerGameServerUpdateUserRusnLevelInfo,
	kMidLayerGameServerUpdateUserSpecialGameInfo,
	kMidLayerGameServerUpdateUserSpecialSingleGameInfo,
	kMidLayerGameServerUpdateRushLevelUserCount,
	kMidLayerGameServerUpdateUserTableData,
	kMidLayerGameServerQueryTableDataConfig,
	kMidLayerGameServerQueryRankNumberInfo,
	kMidLayerGameServerUpdateRankNumberInfo,
	kMidLayerGameServerInsertCustomMatchHistoryPlacing,
	kMidLayerGameServerQueryUserTableData,
	kMidLayerGameServerUpdateUserRankData,
	kMidLayerGameServerInsertUserTableData,
	kMidLayerGameServerDoCommonReward,
	kMidLayerGameServerLoginResponse,
	kMidLayerGameServerQueryUserCommonControlInfo,
	kMidLayerGameServerMiddleLayer2GameServerRequest,
	kMidLayerGameServerQueryMiddleLayer2GameServerRequestList,
	kMidLayerGameServerDeleteMiddleLayer2GameServerRequest,
	kMidLayerGameServerInsertCustomMatchHistoryTableInfo,
	kMidLayerGameServerUpdateUserActivityMissionProgress,
	kMidLayerGameServerRewardItem,
	kMidLayerGameServerCheckUserLoginToken,
	kMidLayerGameServerUpdateUserActivityTaskProgress,
	kMidLayerGameServerUpdateUserSecondMoney,
	kMidLayerGameServerQueryUserSource,
	kMidLayerGameServerUpdateInvitedUserInviteMissionProgress,
	kMidLayerGameServerQueryFriendRankList,
	kMidLayerGameServerSaveReplayRecord,
	kMidLayerGameServerEventTrack,
	kMidLayerGameServerUpdateUserAchievementProgress,
	kMidLayerGameServerUpdateUserTreeTaskProgress,
	kMidLayerGameServerUpdateUserTreeOnlineInfo,
	kMidLayerGameServerUpdateUserBackMissionProgress,
	kMidLayerGameServerInsertUserBackInvitedUser,//绑定回归邀请玩家(对邀请者)
	kMidLayerGameServerDeleteUserBackInviteUser,//解绑回归邀请玩家(对被邀请者)
	kMidLayerGameServerUpdateUserBackInvitedUserProgress,//更新回归邀请玩家进度
	kMidLayerGameServerUserInvitedByShareUrlNotify,//通知分享url邀请
	kMidlayerGameServerUpdateFriendGameTaskProcess,//更新好友房间任务进度
	kMidlayerGameServerUpdateSingleNewUserWeekTaskProgress,//更新新手七日礼包任务进度(服务器内部更新)
	kMidlayerGameServerUpdateFestivalTaskProgress,//更新节日任务进度 60225
	kMidlayerGameServerUpdateCycleTaskProgress,//更新循环任务进度 60226
	kMidlayerGameServerUpdateDrawTaskProcess,//更新抽奖任务进度
	kMidlayerGameServerUpdateTeamGameTaskProgress,
	kMidlayerGameServerClearAccountCache,//通知清除账号信息缓存
	kMidlayerGameServerUpdateSingleNewUserWeekTaskProgressPlus,//更新新新手七日礼包任务进度(服务器内部更新)
	kMidlayerGameServerUpdateNaadamTaskProcess,//更新那达慕任务进度
	kMidLayerGameServerUseItem,
	kMidLayerGameServerSendReward,	//奖励发送到MidLayer领取
    kMidLayerGameServerMax = 65000,

	//client to index server
	kGameServerToIndexServerCheckAppstoreIAP = 70001,
	kMaxClientIndexServerMsg = 80000,

    //smc to midlayer
    kSMCMiddleLayerQueryTotalChipNumRequest = 80001,
    kSMCMiddleLayerQueryTotalChipNumResponse,
    kSMCMiddleLayerAddScoreRequest,
    kSMCMiddleLayerAddScoreResponse,
    kSMCMiddleLayerSubScoreRequest,
    kSMCMiddleLayerSubScoreResponse,
    kSMCMiddleLayerAddBuyRecordRequest,
    kSMCMiddleLayerAddBuyRecordResponse,
    kSMCMiddleLayerGetUserIDRequest,
    kSMCMiddleLayerGetUserIDResponse,
    kSMCMiddleLayerQueryBrokerageRequest,
    kSMCMiddleLayerQueryBrokerageResponse,
    kSMCMiddleLayerAddIPBlackListRequest,
    kSMCMiddleLayerAddIPBlackListResponse,
    kSMCMiddleLayerAddUserIDBlackListRequest,
    kSMCMiddleLayerAddUserIDBlackListResponse,
    kSMCMiddleLayerAddMACBlackListRequest,
    kSMCMiddleLayerAddMACBlackListResponse,
    kSMCMiddleLayerQueryRankingInfoRequest,
    kSMCMiddleLayerQueryRankingInfoResponse,
	kSMCMiddleLayerAddToolRequest,
    kSMCMiddleLayerAddToolResponse,
    kSMCMiddleLayerModifyFullUserInfoRequest,
    kSMCMiddleLayerModifyFullUserInfoResponse,
    kSMCMiddleLayerQueryGiftInfoRequest,
    kSMCMiddleLayerQueryGiftInfoResponse,
    kSMCMiddleLayerModifyGiftInfoRequest,
    kSMCMiddleLayerModifyGiftInfoResponse,
    kSMCMiddleLayerModifyBrokerageRequest,
    kSMCMiddleLayerModifyBrokerageResponse,
    kSMCMiddleLayerRelieveIPBlackListRequest,
    kSMCMiddleLayerRelieveIPBlackListResponse,
    kSMCMiddleLayerRelieveUserIDBlackListRequest,
    kSMCMiddleLayerRelieveUserIDBlackListResponse,
    kSMCMiddleLayerRelieveMACBlackListRequest,
    kSMCMiddleLayerRelieveMACBlackListResponse,
    kSMCMiddleLayerAddSystemBroadcastRequest,
    kSMCMiddleLayerAddSystemBroadcastResponse,
    kSMCMiddleLayerDeleteSystemBroadcastRequest,
    kSMCMiddleLayerDeleteSystemBroadcastResponse,
    kSMCMiddleLayerKickOffUserRequest,
    kSMCMiddleLayerKickOffUserResponse,
    kSMCMiddleLayerMarkWeipaiSuccessRequest,
    kSMCMiddleLayerMarkWeipaiSuccessResponse,
    kSMCMiddleLayerModifyPropertyRequest,
    kSMCMiddleLayerModifyPropertyResponse,
    kSMCMiddleLayerDelPropertyRequest,
    kSMCMiddleLayerDelPropertyResponse,
    kSMCMiddleLayerModifyGiftRequest,
    kSMCMiddleLayerModifyGiftResponse,
    kSMCMiddleLayerDelGiftRequest,
    kSMCMiddleLayerDelGiftResponse,
    kSMCMiddleLayerAddNotificationRequest,
    kSMCMiddleLayerAddNotificationResponse,
    kSMCMiddleLayerDeleteNotificationRequest,
    kSMCMiddleLayerDeleteNotificationResponse,
    kSMCMiddleLayerAddActivityRequest,
    kSMCMiddleLayerAddActivityResponse,
    kSMCMiddleLayerDeleteActivityRequest,
    kSMCMiddleLayerDeleteActivityResponse,
    kSMCMiddleLayerAddFlagRequest,
    kSMCMiddleLayerAddFlagResponse,
    kSMCMiddleLayerDeleteFlagRequest,
    kSMCMiddleLayerDeleteFlagResponse,
    kSMCMiddleLayerAddUserFlagRequest,
    kSMCMiddleLayerAddUserFlagResponse,
    kSMCMiddleLayerFeedBackOperationRequest,
    kSMCMiddleLayerFeedBackOperationResponse,
    kSMCMiddleLayerModifySpeakerConfigRequest,
    kSMCMiddleLayerModifySpeakerConfigResponse,
    kSMCMiddleLayerAddRoomRequest,
    kSMCMiddleLayerAddRoomResponse,
    kSMCMiddleLayerDeleteRoomRequest,
    kSMCMiddleLayerDeleteRoomResponse,
    kSMCMiddleLayerModifyRoomRequest,
    kSMCMiddleLayerModifyRoomResponse,
    kSMCMiddleLayerModifyCommonConfigRequest,
    kSMCMiddleLayerModifyCommonConfigResponse,
    kSMCMiddleLayerAddDailyMissionRequest,
    kSMCMiddleLayerAddDailyMissionResponse,
    kSMCMiddleLayerDeleteDailyMissionRequest,
    kSMCMiddleLayerDeleteDailyMissionResponse,
    kSMCMiddleLayerAddSystemMissionRequest,
    kSMCMiddleLayerAddSystemMissionResponse,
    kSMCMiddleLayerDeleteSystemMissionRequest,
    kSMCMiddleLayerDeleteSystemMissionResponse,
    kSMCMiddleLayerAddExchangeProductRequest,
    kSMCMiddleLayerAddExchangeProductResponse,
    kSMCMiddleLayerDeleteExchangeProductRequest,
    kSMCMiddleLayerDeleteExchangeProductResponse,
    kSMCMiddleLayerAddGameLengthRewardRequest,
    kSMCMiddleLayerAddGameLengthRewardResponse,
    kSMCMiddleLayerDeleteGameLengthRewardRequest,
    kSMCMiddleLayerDeleteGameLengthRewardResponse,
    kSMCMiddleLayerModifyExchangeProductRequest,
    kSMCMiddleLayerModifyExchangeProductResponse,
    kSMCMiddleLayerModifyNotificationRequest,
    kSMCMiddleLayerModifyNotificationResponse,
    kSMCMiddleLayerModifyActivityRequest,
    kSMCMiddleLayerModifyActivityResponse,
	kSMCMiddleLayerPurchaseInfoChanged,
	kSMCMiddleLayerModifyFullUserInfoRequestNew,
	kSMCMiddleLayerModifyFullUserInfoResponseNew,
	kSMCMiddleLayerAddOneSignInMapRequest,
	kSMCMiddleLayerAddOneSignInMapResponse,
	kSMCMiddleLayerRemoveOneSignInMapRequest,
	kSMCMiddleLayerRemoveOneSignInMapResponse,
	kSMCMiddleLayerSendSystemMessageRequest,
	kSMCMiddleLayerSendSystemMessageResponse,
	kSMCMiddleLayerAddBystanderSystemMsgRequest,
	kSMCMiddleLayerAddBystanderSystemMsgResponse,
	kSMCMiddleLayerRemoveBystanderSystemMsgRequest,
	kSMCMiddleLayerRemoveBystanderSystemMsgResponse,
	kSMCMiddleLayerQueryBystanderSystemMsgRequest,
	kSMCMiddleLayerQueryBystanderSystemMsgResponse,
	kSMCMiddleLayerModifyBystanderSystemMsgRequest,
	kSMCMiddleLayerModifyBystanderSystemMsgResponse,
	kSMCMiddleLayerModifyUpdateInfoRequest,
	kSMCMiddleLayerModifyUpdateInfoResponse,

	kSMCMiddleLayerAddAnimationEmotionRequest,
	kSMCMiddleLayerAddAnimationEmotionResponse,
	kSMCMiddleLayerModifyAnimationEmotionRequest,
	kSMCMiddleLayerModifyAnimationEmotionResponse,
	kSMCMiddleLayerDelAnimationEmotionRequest,
	kSMCMiddleLayerDelAnimationEmotionResponse,
	kSMCMiddleLayerQueryAllAnimationEmotionsRequest,
	kSMCMiddleLayerQueryAllAnimationEmotionsResponse,

	kSMCMiddleLayerQueryNewGiftRequest,
	kSMCMiddleLayerQueryNewGiftResponse,

	kSMCMiddleLayerModifyRankRewardConfigRequest,
	kSMCMiddleLayerModifyRankRewardConfigResponse,

	kSMCMiddleLayerQueryTournamentGameConfigRequest,
	kSMCMiddleLayerQueryTournamentGameConfigResponse,
	kSMCMiddleLayerModifyTournamentGameConfigRequest,
	kSMCMiddleLayerModifyTournamentGameConfigResponse,
	kSMCMiddleLayerDeleteTournamentGameConfigRequest,
	kSMCMiddleLayerDeleteTournamentGameConfigResponse,
	kSMCMiddleLayerModifyTournamentRewardRequest,
	kSMCMiddleLayerModifyTournamentRewardResponse,
	kSMCMiddleLayerDeleteTournamentRewardRequest,
	kSMCMiddleLayerDeleteTournamentRewardResponse,
	
	kSMCMiddleLayerQueryLobbyVersion,
	kSMCMiddleLayerModifyLobbyVersion,
	
	kSMCMiddleLayerGetBoundMobileNumberByAccount,
	kSMCMiddleLayerQueryAdWallInfo,
	kSMCMiddleLayerAddAdWallInfo,
	kSMCMiddleLayerModifyAdWallStatus,

	kSMCMiddleLayerQueryNewLobbyVersion,
	kSMCMiddleLayerModifyNewLobbyVersion,
	kSMCMiddleLayerInsertNewLobbyVersion,

	kSMCMiddleLayerGetUserLoginIp,

	kSMCMiddleLayerQuerySystemBroadcast,
	kSMCMiddleLayerInsertSystemBroadcast,
	kSMCMiddleLayerModifySystemBroadcast,
	kSMCMiddleLayerDeleteSystemBroadcast,

	kSMCMiddleLayerUserPay,
	kSMCMiddleLayerSwitchUdpClient,

	kSMCMiddleLayerQueryAndroidPackageUpdateInfo,
	kSMCMiddleLayerModifyAndroidPackageUpdateInfo,
	kSMCMiddleLayerDeleteAndroidPackageUpdateInfo,
	kSMCMiddleLayerQueryIosPackageUpdateInfo,
	kSMCMiddleLayerModifyIosPackageUpdateInfo,
	kSMCMiddleLayerDeleteIosPackageUpdateInfo,
	kSMCMiddleLayerQueryModuleUpdateInfo,
	kSMCMiddleLayerModifyModuleUpdateInfo,
	kSMCMiddleLayerDeleteModuleUpdateInfo,

	kSMCMiddleLayerQueryExchangeItemInfo,
	kSMCMiddleLayerInsertExchangeItemInfo,
	kSMCMiddleLayerModifyExchangeItemInfo,
	kSMCMiddleLayerDeleteExchangeItemInfo,

	kSMCMiddleLayerModifyUserField,
	
	kSMCMiddleLayerUpdateUserMiddleLayerServerID,
	kSMCMiddleLayerRemoveUserMiddleLayerServerID,

	kSMCMiddleLayerCloseFriendTable,
	kSMCMiddleLayerClearTournamentUser,

	kSMCMiddleLayerQueryUserSystemMail,
	kSMCMiddleLayerInsertUserSystemMail,
	kSMCMiddleLayerDeleteUserSystemMail,

	kSMCMiddleLayerQuerySystemNotice,
	kSMCMiddleLayerInsertSystemNotice,
	kSMCMiddleLayerDeleteSystemNotice,
	
	kSMCMiddleLayerReloadCommonReward,
	kSMCMiddleLayerQueryAllLoginAuthServerInfo,
	kSMCMiddleLayerUpdateLoginAuthServerIp,
	kSMCMiddleLayerCloseCustomMatch,

	kSMCMiddleLayerReloadActivityCoinRouletteNotice,

	kSMCMiddleLayerQueryTdModuleUpdateInfo,
	kSMCMiddleLayerModifyTdModuleUpdateInfo,

	kSMCMiddleLayerCheckUserSdkToken,
	kSMCMiddleLayerCheckForbidUser,

	kSMCMiddleLayerSubUserItem,
	kHttpQueryShopInfo,
	kSMCMiddleLayerGetCommonDailyRewardRequest,
	kSMCMiddleLayerGetCommonDailyRewardResponse,
	kSMCMiddleLayerUpdateSystemNotice,
	kSMCMiddleLayerNewPayCallback,//新支付系统回调
    kSMCMiddleLayerMax = 90000,
	//////////////////////////////////////////////////////////////////////////
	
	//Send message to other middle layer to complete action
	kMiddleLayerPresentScoreForToUserRequest = 95000,
	kMiddleLayerPresentScoreForToUserResponse,
	kMiddleLayerAddFriendForAddedUserRequest,
	kMiddleLayerAcceptFriendForAcceptedUserRequest,
	kMiddleLayerAcceptFriendForAcceptedUserResponse,
	kMiddleLayerRejectFriendForRejectedUserRequest,
	kMiddleLayerRemoveFriendForRemovedUserRequest,
	kMiddleLayerRemoveFriendForRemovedUserResponse,
	kMiddleLayerSingleChatMsgForToUserRequest,
	kMiddleLayerBuyGiftForToUserRequest,
	kMiddleLayerBuyGiftForToUserResponse,
	kMiddleLayerNotifyUpdateBlackListRequest,
	kMiddleLayerNotifyUpdateSystemBroadcastRequest,
	kMiddleLayerNotifyUpdateNotificationRequest,
	kMiddleLayerNotifyUpdateActivityRequest,
	kMiddleLayerNotifyUpdateFlagRequest,
	kMiddleLayerNotifyUpdateDailyMissionRequest,
	kMiddleLayerNotifyUpdateSystemMissionRequest,
	kMiddleLayerNotifyUpdateBrokerageRequest,
	kMiddleLayerNotifyUpdatePropertyRequest,
	kMiddleLayerNotifyUpdateGiftRequest,
	
	kMiddleLayerAvatarFrameInfoNotify,
	kMiddleLayerRankRewardAvailableCountNotify,
	kMiddleLayerQueryUserSpringActivityInfo,
	kMiddleLayerDoSpringRoulette,
	kMiddleLayerGetSpringWinScoreReward,

	kMiddleLayerInsertGameHistory,
	kMiddleLayerInsertItemChangeHistory,
	kMiddleLayerInsertSecondMoneyChangeHistory,
	kMiddleLayerInsertLoginHistory,
	kMiddleLayerInsertRegisterHistory,
	kMiddleLayerInsertCouponChangeHistory,
	kMiddleLayerInsertHuaFeiQuanChangeHistory,
	kMiddleLayerInsertSignInHistory,
	kMiddleLayerInsertRouletteHistory,
	kMiddleLayerInsertPresentItemHistory,
	kMiddleLayerInsertCofferHistory,
	kMiddleLayerInsertFruitMachineNormalGameRecord,
	kMiddleLayerInsertTreasureHuntGameRecord,
	kMiddleLayerInsertFruitMachineCompareGameRecord,
	kMiddleLayerInsertFishingMissionRecord,
	kMiddleLayerInsertFishingFlopGameRecord,
	kMiddleLayerInsertFishingLobbyPlayLotteryRecord,
	kMiddleLayerInsertUserVipRewardRecord,
	kMiddleLayerInsertFishingCardRecord,
	kMiddleLayerInsertFishingTournamentGameRecord,
	kMiddleLayerInsertNormalSlotsGameRecord,
	kMiddleLayerInsertFreeSlotsGameRecord,
	kMiddleLayerInsertCardsSlotsGameRecord,
	kMiddleLayerInsertFishingGetDailyMissionRewardRecord,
	kMiddleLayerInsertFishingRefreshDailyMissionRecord,
	kMiddleLayerInsertFishingAttackBossRecord,
	kMiddleLayerInsertModifyPasswordRecord,
	kMiddleLayerInsertModifyCofferPasswordRecord,
	kMiddleLayerInsertBindMobileRecord,
	kMiddleLayerInsertModifyLoginProtectionRecord,
	kMiddleLayerInsertVipExpChangeRecord,
	kMiddleLayerInsertFishingNewGuideRewardRecord,
	kMiddleLayerInsertFishingBossRouletteRecord,
	kMiddleLayerInsertFishingGetTournamentRewardRecord,
	kMiddleLayerInsertFishingApplyTournamentRecord,
	kMiddleLayerInsertFishingLotteryBuyRecord,
	kMiddleLayerInsertFishingLotteryGetRewardRecord,
	kMiddleLayerInsertFishingUnlockPetRecord,
	kMiddleLayerInsertFishingUpgradePetRecord,
	kMiddleLayerInsertFishingUsePetSkillRecord,
	kMiddleLayerInsertMessageHandleInfo,
	kMiddleLayerInsertFishingHornRecord,
	kMiddleLayerInsertFishingMoneyTreeRecord,
	kMiddleLayerInsertFishingElectricEelRecord,
	kMiddleLayerInsertFishingTreasureMapRecord,
	kMiddleLayerInsertFishingItemChangeRecord,
	kMiddleLayerInsertFishingShopRecord,
	kMiddleLayerInsertFishingMoneyTree,
	kMiddleLayerInsertFishingExchangeRecord,
	kMiddleLayerInsertGenerateSystemMailRecord,
	kMiddleLayerInsertGetSystemMailRewardRecord,
	kMiddleLayerInsertFishingTreasureMapRewardRecord,
	kMiddleLayerInsertFishingKillBossRecord,
	kMiddleLayerInsertFishingStuntRecord,
	kMiddleLayerInsertFishingNewDailyMissionRewardRecord,
	kMiddleLayerInsertFishingNewDailyMissionActivityRewardRecord,
	kMiddleLayerInsertFishingDivinationRecord,
	kMiddleLayerInsertFishingExchangeGiftRecord,
	kMiddleLayerInsertUserActivityCoinRouletteRecord,
	kMiddleLayerInsertFishingPayRebateRewardRecord,
	kMiddleLayerInsertFishingYiZhuanFanPanRecord,
	kMiddleLayerInsertFishTycoonRecord,
	kMiddleLayerInsertRankingMatchGradeHistory,
	kMiddleLayerInsertFishDailySignInRecord,
	kMiddleLayerInsertFishWeChatGiftRecord,
	kMiddleLayerInsertFishCertificationRecord,
	kMiddleLayerInsertFishNewUserGiftRecord,
	kMiddleLayerInsertFishNewUserGuideRecord,
	kMiddleLayerInsertFishNewUserTaskRecord,
	kMiddleLayerInsertFishOnlineRewardRecord,
	kMiddleLayerInsertFishPetGuideRecord,
	kMiddleLayerInsertAchievementRecord,
	kMiddleLayerInsertFishStartUpGiftRecord,
	kMiddleLayerInsertAdvertRewardRecord,
	kMiddleLayerInsertInviteRewardRecord,
	kMiddleLayerInsertCommonShareRewardRecord,
	kMiddleLayerInsertFish7DaysChallengeRecord,
	kMiddleLayerInsertFishVipMakeUpMoneyRecord,
	kMiddleLayerInsertFishWishingWellRecord,
	kMiddleLayerInsertFishingExpertRecord,
	kMiddleLayerInsertFishLuckyDrawRecord,
	kMiddleLayerInsertFishLeJaguarGiftRecord,
	kMiddleLayerInsertFishActivityTaskRecord,
	kMiddleLayerInsertPokerSecondMoneyRecord,
	kMiddleLayerInsertFishLuckyDraw2Record,
	kMiddleLayerInsertFishAccumulativePayActivityRecord,
	kMiddleLayerInsertInviteMissionRewardRecord,
	kMiddleLayerInsertFishPovertyRecord,
	kMiddleLayerModifyNickNameRecord,
	kMiddleLayerInsertFishGemGameRecord,
    kMiddleLayerEquipmentExchangeRecord,
	kMiddleLayerInsertBlackUserLoginHistory,
	kMiddleLayerFishShuangDanSignHistory,
	kMiddleLayerFishGodTreasureHistory,
	kMiddleLayerFishShuangDanFishMapHistory,
	kMiddleLayerFishTaiShootDetailRecord,
	kMiddleLayerFishNewArithmeticInfoRecord,
	kMiddleLayerInsertFishing7DayBuyGiftBagRewardRecord,
};

#endif
