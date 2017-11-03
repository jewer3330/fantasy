local function _addDefine(defs, add)
	local deflen = string.len(defs)
	if deflen > 0 then
		defs = defs .. ';'
	end
	defs = defs .. add
	return defs
end

local function _addDefines(defs, adds)
	local deflen = string.len(defs)
	if deflen > 0 then
		defs = defs .. ';'
	end
	for i = 1, #adds do
		defs = defs .. ';' .. adds[i]
	end
	return defs
end

local function addDefine(defs, item, define)
	defs.Items = _addDefine(defs.Items, item)
	defs.Defins = _addDefine(defs.Defins, define)
end

local function addDefines(defs, items, defines)
	defs.Items = _addDefines(defs.Items, items)
	defs.Defins = _addDefines(defs.Defins, defines)
end

--raiseEvent节点数据定义
RaiseDefine = {
	Items = '',
	Defins = ''
}
addDefine(RaiseDefine, 'Interrupt_Skill', 'skillid:System.Int32-logicid:System.Int32')

--Detect节点数据定义
DetectDefine = {
	Items = '',
	Defins = ''
}
addDefine(DetectDefine, 'Damage', 'RealDmg:System.Int32-Dmg:System.Int32-ActorID:System.UInt64')
addDefine(DetectDefine, 'Cause_Damage', "type:System.Int32-target:System.UInt64-damage:System.Int32")
addDefine(DetectDefine, 'Start_Fire', 'null')
addDefine(DetectDefine, 'Hold_Fire', 'Null:null')
addDefine(DetectDefine, 'Bullet_Num', 'BulletNum:System.Int32')
addDefine(DetectDefine, 'Actor_Dead', 'Null:null')
addDefine(DetectDefine, 'Actor_Spawn', 'Null:null')
addDefine(DetectDefine, 'Actor_POS', 'fx:System.Single-fy:System.Single-vx:System.Single-vy:System.Single-orient:System.Single')
addDefine(DetectDefine, 'Actor_StopMove', 'fx:System.Single-fy:System.Single-orient:System.Single')
addDefine(DetectDefine, 'Kill_Target', 'target:System.UInt64-damage:System.Int32-skillId:System.Int32')
addDefine(DetectDefine, 'Attack_Target', 'target:System.UInt64-damage:System.Int32')
addDefine(DetectDefine, 'Start_Skill', 'null')
addDefine(DetectDefine, RaiseDefine.Items, RaiseDefine.Defins..'-extendid:System.Int32')
addDefine(DetectDefine, 'Divorce_Fight', 'null')
addDefine(DetectDefine, 'EnegyShiled_Decrease', 'change:System.Int32-curValue:System.Int32-lastValue:System.Int32')
addDefine(DetectDefine, 'EnegyShiled_Increase', 'change:System.Int32-curValue:System.Int32-lastValue:System.Int32')
addDefine(DetectDefine, 'Enter_Fight', 'null')
addDefine(DetectDefine, 'Assistant_Kill', 'null')
addDefine(DetectDefine, 'Marking', 'target:System.UInt64')


--WeaponDetect节点数据定义
WeaponDetectDefine = {
	Items = '',
	Defins = ''
}
addDefine(WeaponDetectDefine, 'Weapon_Hit', 'ActorID:System.UInt64')
