//
//  ZZCViewController2.m
//  ZZCMacroDefine_Example
//
//  Created by zzc on 2021/6/9.
//  Copyright © 2021 zhengzhicheng. All rights reserved.
//

#import "ZZCViewController2.h"
#import <ZZCMacroDefine/ZZCMacroDefine.h>

@interface ZZCViewController2 ()

@end

@implementation ZZCViewController2

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

//    KAdd_Observer(self, action, @"name", nil);
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(action) name:@"hehe" object:nil];
    
}

- (void)action{
    NSLog(@"aa");

}

- (void)action:(NSNotification *)info{
    NSLog(@"aa%@", info);
}


@end
