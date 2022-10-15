#include "../Header/VectorMain.h"

void VectorMain::PrintXMVectorInfo()
{
	cout.setf(ios_base::boolalpha);
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math can not supported" << endl;
		return;
	}

	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.f, 2.f, 3.f, 4.f);
	XMVECTOR v = XMVectorReplicate(-2.f);
	XMVECTOR w = XMVectorSplatZ(u);

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
}

void VectorMain::PrintXMVectorFuncInfo()
{
	cout.setf(ios_base::boolalpha);

	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return;
	}

	XMVECTOR n = XMVectorSet(1.f, 0.f, 0.f, 0.f);
	XMVECTOR u = XMVectorSet(1.f, 2.f, 3.f, 0.f);
	XMVECTOR v = XMVectorSet(-2.f, 1.f, -3.f, 0.f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.f, 0.f);



	XMVECTOR ProjW;
	XMVECTOR PrepW;
	XMVector3ComponentsFromNormal(&ProjW, &PrepW, w, n);

	bool IsEqual = XMVector3Equal(ProjW + PrepW, w) != 0;
	bool IsNotEqual = XMVector3NotEqual(ProjW + PrepW, w) != 0;

	XMVECTOR AngleVector = XMVector3AngleBetweenVectors(ProjW, PrepW);
	float AngleRadius = XMVectorGetX(AngleVector);
	float AngleDegrees = XMConvertToDegrees(AngleRadius);

	cout << "n = " << n << endl;
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;

	cout << "u + v = " << u + v << endl;
	cout << "u - v = " << u - v << endl;
	cout << "10.f * u = " << 10.f * u << endl;
	cout << "||u|| = " << XMVector3Length(u) << endl;
	cout << "u / ||u|| = " << XMVector3Normalize(u) << endl;
	cout << "u dot v = " << XMVector3Dot(u, v) << endl;
	cout << "u x v = " << XMVector3Cross(u, v) << endl;
	cout << "ProjW = " << ProjW << endl;
	cout << "PrepW = " << PrepW << endl;
	cout << "ProjW + PrepW == w = " << IsEqual << endl;
	cout << "ProjW + PrepW != w = " << IsNotEqual << endl;
	cout << "angel = " << AngleDegrees << endl;
}

int main()
{
	VectorMain::PrintXMVectorInfo();

	cout << endl << endl;

	VectorMain::PrintXMVectorFuncInfo();
}