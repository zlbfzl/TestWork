//
//  ZCLibCustomer.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLibLib. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  配置用户信息
 */
@interface ZCLibCustomer : NSObject

/**
 *  用户id
 */
@property(nonatomic,strong) NSString *customerId;

/**
 *  用户昵称
 */
@property(nonatomic,strong) NSString *customerName;

/**
 *  用户头像
 */
@property(nonatomic,strong) NSString *customerAvatar;



@end
