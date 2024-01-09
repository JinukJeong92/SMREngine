#include "EngineMode.h"

namespace {
	uint32_t flags = 0;
}

void EngineFlag::AddFlag(const EngineMode flag)
{
	flags |= static_cast<uint32_t>(flag);
}

void EngineFlag::RemoveFlag(const EngineMode flag)
{
	flags &= ~static_cast<uint32_t>(flag);
}

bool EngineFlag::IsEqualFlag(const EngineMode flag1, const EngineMode flag2)
{
	return static_cast<uint32_t>(flag1) & static_cast<uint32_t>(flag2);
}

bool EngineFlag::IsFlagSet(const EngineMode flag)
{
	return flags & static_cast<uint32_t>(flag);
}

void EngineFlag::ToggleFlag(const EngineMode flag)
{
	IsFlagSet(flag) ? RemoveFlag(flag) : AddFlag(flag);
}
