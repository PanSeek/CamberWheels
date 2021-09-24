#include <windows.h>

auto fill(unsigned __int32 address, unsigned __int8 value, unsigned __int32 size) -> void {
	DWORD oldProt{ 0 };
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, PAGE_READWRITE, &oldProt);
	memset(reinterpret_cast<void*>(address), value, size);
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, oldProt, &oldProt);
	return;
}

auto raw(unsigned __int32 address, const char* RawData, unsigned __int16 size) -> void {
	DWORD oldProt{ 0 };
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, PAGE_READWRITE, &oldProt);
	memcpy(reinterpret_cast<void*>(address), RawData, size);
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, oldProt, &oldProt);
	return;
}

class CMain {
public:
	CMain() {
		fill(0x6AA6EE, 0x90, 0x6);
		fill(0x6AA954, 20.f, 0x4);
	};
	~CMain() {
		raw(0x6AA6EE, "\x0F\x85\x9B\x03\x00\x00", 0x6);
		raw(0x6AA954, "\x8C\x8B\x85\x00", 0x4);
	};
}; CMain plugin;
