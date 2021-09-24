#include <windows.h>

class CMain {
public:
	CMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA954), 4, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x6AA954), 20.f, 0x4);
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA954), 4, oldProt, &oldProt);
	};
	~CMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA954), 4, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x6AA954), "\x8C\x8B\x85\x00", 0x4);
		VirtualProtect(reinterpret_cast<LPVOID>(0x6AA954), 4, oldProt, &oldProt);
	};
	DWORD oldProt;
}; CMain plugin;
