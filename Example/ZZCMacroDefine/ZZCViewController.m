//
//  ZZCViewController.m
//  ZZCMacroDefine
//
//  Created by zhengzhicheng on 06/09/2021.
//  Copyright (c) 2021 zhengzhicheng. All rights reserved.
//

#import "ZZCViewController.h"
#import "ZZCViewController2.h"
#import <ZZCMacroDefine/ZZCMacroDefine.h>

@interface ZZCViewController ()

@end

@implementation ZZCViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
//    KPost_Notify(@"name", nil);
//    [[NSNotificationCenter defaultCenter] postNotificationName:@"hehe" object:@{@"key" : @"a"}];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"hehe" object:nil];
    
    UIButton *bnt = [UIButton buttonWithType:UIButtonTypeCustom];
    bnt.frame = CGRectMake(0, 100, 60, 44);
    [bnt setTitle:@"跳转" forState:UIControlStateNormal];
    [bnt setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    [bnt addTarget:self action:@selector(btnAction:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:bnt];
}

- (void)btnAction:(UIButton *)bnt{
    ZZCViewController2 *vc = [ZZCViewController2 new];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
