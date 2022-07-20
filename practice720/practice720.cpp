#include <iostream>

using namespace std;

// 은닉성

//멤버 접근지정자
// - public : 공개적
// - protected : 상속자 까지 사용가능
// - private : 클래스 내부에서만 사용가능

//상속접근지정자 
// 자식클래스 에게 상속 할때의 접근제한
// - public : 공개적상속 부모클래스의 설계 그대로 public->public // protected->protected
// - protected : public->protected / protected->protected
// - private : public->private / protected->private

class Car
{
public: //멤버접근지정자
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TrunKey()
	{
		RunEngine();
	}
protected:
	void RunEngine() {} // 엔진을 구동시킨다

private:
	void DisassembleCar() {} //차를분해한다
	void ConnectCircuit() {} // 전기선 연결
};

class SuperCar : public Car //상속접근 지정자
{

public:
	void PushRemoteController()
	{
		RunEngine();
	}
};


//캡슐화
//연관된 데이터와 함수를 논리적으로 묶어놓은것
class Berserker
{
public:
	int GetHp() { return mHP; }

	// 사양 : 체력이 50이하로 떨어지면 버서커 모드발동
	void SetHp(int hp)
	{
		mHP = hp;
		if (mHP <= 50)
		{
			SetBerserkerMode();
		}
	}

	
private:
	int mHP = 100;

private:
	void SetBerserkerMode()
	{
		cout << "매우강해짐" << endl;
	}
};

int main()
{
	Berserker b;

	b.SetHp(20);
}