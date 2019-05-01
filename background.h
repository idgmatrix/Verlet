// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

#ifndef BACKGROUND_H
#define BACKGROUND_H

extern int harray[100];			// 곡선의 높이 값을 저장하는 배열

void SetCollisionBound(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);
int GetHeight(int x);

#endif