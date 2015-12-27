//
//  ZCLibMessage.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibRich.h"

/**
 *  配置消息记录
 */
@interface ZCLibMessage : NSObject


/**
 *  会话时间
 */
@property (nonatomic , strong) NSString *date;

/**
 *  内容
 */
@property (nonatomic , strong) NSString *content;

/**
 *  会话id
 */
@property (nonatomic , strong) NSString *cid;

/**
 *  会话类型0，用户，1机器人 2客服
 */
@property (nonatomic , strong) NSString *action;

/**
 *  用户id
 */
@property (nonatomic , strong) NSString *sender;

/**
 *  用户名称
 */
@property (nonatomic , strong) NSString *senderName;

/**
 *  发送,0，自己，1机器人，2客服
 */
@property (nonatomic , assign) int      senderType;

/**
 *  头像
 */
@property (nonatomic , strong) NSString *senderFace;

/**
 *  发送时间戳 -long
 */
@property (nonatomic , strong) NSString *t;

/**
 *  发送时间
 */
@property (nonatomic , strong) NSString *ts;

/**
 *  客服ID
 */
@property (nonatomic , strong) NSString *receiver;

/**
 *  客服名称
 */
@property (nonatomic , strong) NSString *receiverName;

/**
 *  下线类型
 */
@property (nonatomic , strong) NSString *offlineType;

/**
 *  客服头像
 */
@property (nonatomic , strong) NSString *receiverFace;

/**
 *  是否已读
 */
@property (nonatomic , assign) BOOL isRead;

/**
 *  上传进度
 */
@property (nonatomic , assign) float progress;

/**
 *  发送状态，1 开始发送，2发送失败，0，发送完成
 */
@property (nonatomic , assign) int  sendStatus;

/**
 *  是否播放
 */
@property (nonatomic , assign) BOOL isPlaying;

/**
 *  是否是历史消息
 */
@property (nonatomic , assign) BOOL isHistory;

/**
 *  ZCLibRic创建的对象
 */
@property (nonatomic , strong) ZCLibRich *richModel;

/**
 *  提醒,上下线等
 */
@property (nonatomic , strong) NSString *sysTips;

/**
 *  提示类型
 */
@property (nonatomic , assign) int tipStyle;


/**
 *  初始化
 *
 *  @param dict 数据解析后的数据字典类型
 *
 *  @return ZCLibMessage
 */
-(id) initWithMyDict:(NSDictionary *)dict;

@end
