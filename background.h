// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

#ifndef BACKGROUND_H
#define BACKGROUND_H

extern int harray[100];			// ��� ���� ���� �����ϴ� �迭

void SetCollisionBound(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);
int GetHeight(int x);

#endif