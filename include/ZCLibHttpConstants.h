//
//  HttpConstants.h
//  SobotSDK
//
//  Created by 张新耀 on 15/8/5.
//  Copyright (c) 2015年 sobot. All rights reserved.
//

#import <CoreText/CoreText.h>
/**
 *  超时时间
 */
#define HttpGetTimeOut       10
#define HttpPostTimeOut      30
#define HttpPostSmallTimeOut 10

#define HttpRequestType  1 // 1,ASI  2,NSURLConnection


#define HttpNetWorkError    @"网络错误"
#define HttpNetWorkTimeOut  @"网络连接超时"

/**
 *  开始请求，每次发送请求时调用
 */
typedef void(^StartBlock)();

/**
 *  请求成功
 *
 *  @param dict 成功后，解析的返回
 */
typedef void(^CompleteBlock)(NSDictionary *dict);

/**
 *  请求完成，不管失败、成功，只要完成都会执行，可为nil
 *
 *  @param response 请求返回NSURLResponse
 */
typedef void(^FinishBlock)(id response,NSData  *data);

/**
 *  请求失败
 *
 *  @param response     请求返回NSURLResponse
 *  @param connectError 失败的connectError
 */
typedef void(^FailBlock)(id response,NSString *errorMsg,NSError *connectError);


/**
 *  上传、下载进度
 *
 *  @param progress 上传、下载进度，如0.2，0.5
 */
typedef void(^ProgressBlock)(CGFloat progress);


////////////////////////////////////////////////////////////////
/**
 * 接口
 */
////////////////////////////////////////////////////////////////

#define API_HOST @"http://open.sobot.com"
//#define API_HOST @"http://ppzuche1.sobot.com"
//#define API_HOST @"http://test.sobot.com"

/**
 *  接收消息
 *
 *  @return http://open.sobot.com/chat/h5sdk/index.html?version=1.3.1
 */
#define API_ReceivedMessage [NSString stringWithFormat:@"%@/chat/h5sdk/index.html?version=%@",API_HOST,zcGetAppVersion()]

/**
 *  获取初始化信息
 *
 *  @param sysNum 企业编号
 *  @param uiid   设备唯一编号
 *
 *  @return http://open.sobot.com/chat/sdk/user/v1/init.action?sysNum=%@&partnerId=%@&way=5&tel=%@&uname=%@&email=%@&system=%@&from=3&version=%@ 拼接sysNum,uiid,tel,uname,email,system,zcGetAppVersion()
 */
#define API_InitRobot(sysNum,uiid,tel,uname,email,system) [NSString stringWithFormat:@"%@/chat/sdk/user/v1/init.action?sysNum=%@&partnerId=%@&way=5&tel=%@&uname=%@&email=%@&system=%@&from=3&version=%@",API_HOST,sysNum,uiid,tel,uname,email,system,zcGetAppVersion()]


/**
 *  获取聊天记录接口
 *  post请求，uid startTime endTime
 *
 *  @return http://open.sobot.com/chat/sdk/user/v1/chatdetail.action
 */
#define API_ChatList [NSString stringWithFormat:@"%@/chat/sdk/user/v1/chatdetail.action",API_HOST]


/**
 *  人机问答
 *  post:requestText,sysNum,uid,cid
 *
 *  @return  http://open.sobot.com/chat/sdk/user/v1/chat.action
 */
#define API_SendToRobot [NSString stringWithFormat:@"%@/chat/sdk/user/v1/chat.action",API_HOST]


/**
 *  转人工接口
 *  post:uid,cid
 *
 *  @return  http://open.sobot.com/chat/sdk/user/v1/chatconnect.action
 */
//#define API_UserConnect [NSString stringWithFormat:@"%@/chat/sdk/user/v1/connect.action",API_HOST]
#define API_UserConnect [NSString stringWithFormat:@"%@/chat/sdk/user/v1/chatconnect.action",API_HOST]


/**
 *  用户给客服发送消息
 *  post:uid,cid,content
 *
 *  @return   http://open.sobot.com/chat/sdk/user/v1/send.action
 */
#define API_SendToUser [NSString stringWithFormat:@"%@/chat/sdk/user/v1/send.action",API_HOST]


/**
 *  上传文件接口
 *  post:sysNum,type
 *  @return  http://open.sobot.com/chat/sdk/user/v1/sendFile.action
 */
#define API_UploadFile [NSString stringWithFormat:@"%@/chat/sdk/user/v1/sendFile.action",API_HOST]

/**
 *  用户满意度接口
 *  post:cid ,userId ,type ,source ,problem ,suggest ,isresolve
 *
 *  @return  http://open.sobot.com/chat/sdk/user/v1/comment.action
 */
#define API_Comment [NSString stringWithFormat:@"%@/chat/sdk/user/v1/comment.action",API_HOST]


/**
 *  用户主动下线
 *  post: cid,uid
 *
 *  @return  http://open.sobot.com/chat/sdk/user/v1/out.action
 */
#define API_Logout [NSString stringWithFormat:@"%@/chat/sdk/user/v1/out.action",API_HOST]
