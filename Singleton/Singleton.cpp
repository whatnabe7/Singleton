// Singleton.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<string>

class Data {
public:
	int no;
	std::string name;
	Data() { no = 1; name = "aaa"; }
};

class RegisterNote {
private:
public:
	Data data;
private:
	RegisterNote() {
		data = Data();
	}
public:
	static RegisterNote* p_Instance;
	static RegisterNote* getInstance() {
		return p_Instance;
	}
	static void create() {
		if (!p_Instance) {
			p_Instance = new RegisterNote;
		}
	}
	static void destroy() {
		if (p_Instance) {
			delete p_Instance;
			p_Instance = NULL;
		}
	}
};

RegisterNote* RegisterNote::p_Instance = NULL;

int main()
{
	RegisterNote::create();
	RegisterNote* reg = RegisterNote::getInstance();
	printf("%d %s\n", reg->data.no, reg->data.name.c_str());
	getchar();
	RegisterNote::destroy();
	return 0;
}

