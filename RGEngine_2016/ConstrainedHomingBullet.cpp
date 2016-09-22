#include "ConstrainedHomingBullet.h"

CConstrainedHomingBullet::CConstrainedHomingBullet(BulletShape shapeType, float x,
	float y, float angle, float speed, float maxAngleRate)
	:CBullet(x, y, angle, 0, speed, 0), MaxAngleRate(maxAngleRate)
{
}


CConstrainedHomingBullet::~CConstrainedHomingBullet()
{
}

void CConstrainedHomingBullet::Move()
{
	//��ȸ ���ӵ� ���
	float angleRate = GetMyShipAngle(this->center.x, this->center.y)-Angle;
	
	//��ȸ ���ӵ��� 0.0~1.0�� ������ ����
	angleRate -= floor(angleRate);
	

	if (angleRate <= MaxAngleRate || (1.0f - angleRate) <= MaxAngleRate)
	{
		//��ȸ ���ӵ��� �ִ� ��ȸ ���ӵ� �����̸�
		//��ȸ ���ӵ��� ��ȸ
		Angle += angleRate;
	}
	else 
	{
		//��ȸ ���ӵ��� �ִ� ��ȸ ���ӵ����� Ŭ ���
		//�ִ� ��ȸ ���ӵ��� ��ȸ
		Angle += (angleRate < 0.5f) ? MaxAngleRate : -MaxAngleRate;
	}

	//������ 0.0~1.0�� ������ ����
	Angle -= floor(Angle);

	//�⺻���� ź �̵� ó�� ȣ��
	CBullet::Move();
}

float CConstrainedHomingBullet::GetMyShipAngle(float x, float y)
{
	return NULL;
	//�÷��̾� ����
		//return atan2f(RGApp->GetScene<CPlayStage>()->GetPlayer()->realy - y,
		//	RGApp->GetScene<CPlayStage>()->GetPlayer()->realx - x) / D3DX_PI / 2;
}
