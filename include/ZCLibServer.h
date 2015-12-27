//
//  ZCLibServer.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "ZCLibMessageConstants.h"
#import "ZCLibStatusDefine.h"
#import "ZCLibConfig.h"
#import "ZCLibCustomer.h"


/**
 *  ZC 服务核心类。
 *  <p/>
 *  所有 ZC 相关方法、监听器都由此调用和设置。
 */
@interface ZCLibServer : NSObject

/**
 *  获取类单例。
 *
 *  @return 智齿核心处理类单例。
 */
+ (instancetype)sharedZCLibServer;


/**
 *  获取初连接成功的对象
 可使用此对象判断，是否已经连接成功
 *
 *  @return 初始化
 */
- (ZCLibConfig *) getZCLibConfig;



/**
 *  连接到智齿客服
 成功调用一次就可以，主要初始化一些必要参数，自动连接人工服务通道
 *
 *  @param initInfo             初始化参数
 *  @param successBlock         初始化成功，返回初始化对象，同 getZClibConfig
 *  @param errorBlock           初始化失败，返回失败状态
 *  @param sysNumIncorrectBlock 企业编号错误
 */
- (void)initWithSysNum:(ZCLibInitInfo *) initInfo
              delegate:(id<ZCMessageDelegate>) delegate
               success:(void (^)(ZCLibConfig *config))successBlock
                 error:(void (^)(ZCStatusCode status))errorBlock
       sysNumIncorrect:(void (^)(NSString *inEnterpriseId))sysNumIncorrectBlock;


/**
 *  转接人工
 *
 *  @param successBlock 转接成功，转接状态
 *  @param errorBlock   转接失败
 */
-(void)connectOnlineCustomer:(void(^)())startBlock result:(void (^)(NSDictionary *dict, ZCConnectUserStatusCode status)) resultBlock;


/**
 *  获取人工回复消息或上下线提醒 代理
 *
 *  @param delegate 消息接收代理
 */
-(void)setReceivedMessageDelegate:(id<ZCMessageDelegate>) delegate;


/**
 *  解析接收到得消息字符串
 *
 *  @param JSONString 
 */
-(void)receivedMessageParsed:(NSString *)JSONString;


/**
 *  拼接显示对象
 *
 *  @param text          显示的文字
 *  @param msgType       消息类型
 *  @param voiceDuration 如果是音频，就是音频时长
 *  @param style         提示信息，还是普通信息
 *  @param isSend        是否是发送者消息
 *  @param nickname      发送的昵称
 *
 *  @return <#return value description#>
 */
-(ZCLibMessage *)setLocalDataToArr:(NSString *) text
                              type:(int)msgType
                          duration:(NSString *) voiceDuration
                             style:(NSInteger) style
                              send:(BOOL) isSend name:(NSString *)nickname;

/**
 *
 *  发送消息
 跟进ZCLibConfig中的类型，自动判断
 *
 *  @param message  消息体
 *  @param type     消息类型
 *  @param duration 声音长度，如00:20,字符串类型，直接用于显示
 *  @param startBlock    开始发送，返回用于显示的消息模型
 *  @param successBlock  发送成功，返回用于显示状态的消息模型
 *  @param progressBlock 发送进度，主要是图片和语言需要
 *  @param failBlock     发送失败，包括内容为空、文件不纯在、网络错误等，返回用于显示状态的消息模型，如果消息未发送，没有模型返回
 */
-(void)sendMessage:(NSString *)message
           msgType:(ZCMessageType ) type
          duration:(NSString *)duration
             start:(void(^)(ZCLibMessage *message)) startBlock
           success:(void(^)(ZCLibMessage *message,ZCMessageSendCode sendCode)) successBlock
          progress:(void(^)(ZCLibMessage *message)) progressBlock
              fail:(void(^)(ZCLibMessage *message,ZCMessageSendCode errorCode)) failBlock;

/**
 *  获取历史记录
 *
 *  @param pageNum      当前页数
 *  @param size         每页条目
 *  @param startBlock   开始查询
 *  @param successBlock 查询成功
 *  @param failedBlock  查询失败
 */
-(void)getHistoryMessages:(int) pageNum
                 pageSize:(int) size
                    start:(void(^)()) startBlock
                  success:(void(^)(NSMutableArray *messages,ZCNetWorkCode sendCode)) successBlock
                   failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 *  评价客户
 *
 *  @param params 参数说明
 cid 会话编号
 isresolve 是否解决问题，1是没有解决，0解决
 problem = 问题编号，没有传空 机器人：答非所问1 理解能力差2 问题不能回答3 不礼貌4  人工： 服务态度差,5  回答不及时,6 没解决问题,7 不礼貌,8
 source 分数（✨）
 suggest 描述
 type   0评价机器人，1评价人工
 userId 用户uid
 */
-(void)doComment:(NSMutableDictionary *) params;



/**
 *  登出
 */
-(void)logOut;


/**
 *  下载文件
 *
 *  @param url           文件URL
 *  @param startBlock    开始下载
 *  @param successBlock  下载完成
 *  @param progressBlock 下载进度
 *  @param failBlock     下载结束
 */
-(void)downFileWithURL:(NSString *)url
             start:(void(^)()) startBlock
           success:(void(^)(NSData *data)) successBlock
          progress:(void(^)(float progress)) progressBlock
              fail:(void(^)(ZCNetWorkCode errorCode)) failBlock;

@end
