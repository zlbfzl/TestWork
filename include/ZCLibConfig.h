//
//  ZCLibConfig.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLibLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibInitInfo.h"

/**
 *  配置信息
 */
@interface ZCLibConfig : NSObject

/**
 *  用户id
 */
@property (nonatomic , strong) NSString *uid;

/**
 *  客服不在线标题
 */
@property (nonatomic , strong) NSString *adminNonelineTitle;

/**
 *  机器人头像logo
 */
@property (nonatomic , strong) NSString *robotLogo;

/**
 *  用户超时下线
 */
@property (nonatomic , strong) NSString *userOutWord;

/**
 *  客服欢迎语
 */
@property (nonatomic , strong) NSString *adminHelloWord;

/**
 *  用户无应答提示时间
 */
@property (nonatomic , assign) int      userTipTime;

/**
 *  用户无应答提示文案
 */
@property (nonatomic , strong) NSString *userTipWord;

/**
 *  机器人欢迎语
 */
@property (nonatomic , strong) NSString *robotHelloWord;

/**
 *  客服无应答提示文案
 */
@property (nonatomic , strong) NSString *adminTipWord;

/**
 *  企业名称
 */
@property (nonatomic , strong) NSString *companyName;

/**
 *  接入方式,1只有机器人 3.智能客服-机器人优先 4智能客服-人工客服优先',
 */
@property (nonatomic , assign) int      type;

/**
 *  会话id
 */
@property (nonatomic , strong) NSString *cid;

/**
 *  公司付费状态 0试用 1免费 2永久 10都付费 11机器人付费 12人工客服付费
 */
@property (nonatomic , assign) int      companyStatus;

/**
 *  机器人昵称
 */
@property (nonatomic , strong) NSString *robotName;

/**
 *  是否是黑名单 0否 1是
 */
@property (nonatomic , assign) BOOL     isblack;

/**
 *  用户超时下线时间
 */
@property (nonatomic , assign) int      userOutTime;

/**
 *  机器人未知措辞
 */
@property (nonatomic , strong) NSString *robotUnknownWord;

/**
 *  标示
 */
@property (nonatomic , strong) NSString *token;

/**
 *  颜色代码
 */
@property (nonatomic , strong) NSString *color;

/**
 *  1 开启语音 2 关闭语音功能 3只选择机器人客服
 */
@property (nonatomic , assign) int      onORoff;

/**
 *  客服无应答提示时间
 */
@property (nonatomic , assign) int      adminTipTime;

/**
 *  appKey
 */
@property (nonatomic , strong) NSString *appKey;

/**
 *  是否人工服务
 */
@property (nonatomic , assign) BOOL     isArtificial;

/**
 *  评论人工，以逗号隔开
 */
@property (nonatomic , strong) NSString *manualCommentTitle;

/**
 *  评论机器人
 */
@property (nonatomic , strong) NSString *robotCommentTitle;

/**
 *  是否转过人工
 */
@property (nonatomic , assign) BOOL     isLastMessage;

/**
 *  初始化参数
 *  自己设置，服务器端未返回
 */
@property (nonatomic , strong) ZCLibInitInfo *zcinitInfo;

/**
 *  对象封装
 *
 *  @param dict 获取数据解析后的数据
 *
 *  @return ZCLibConfig
 */
-(id)initWithMyDict:(NSDictionary *)dict;

@end
