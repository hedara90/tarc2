EventScript_Meditate::
# 2 "data/scripts/tarc_scripts.pory"
	msgbox EventScript_Meditate_Text_0, MSGBOX_YESNO
# 3 "data/scripts/tarc_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Meditate_2
EventScript_Meditate_1:
# 8 "data/scripts/tarc_scripts.pory"
	releaseall
	return

EventScript_Meditate_2:
# 4 "data/scripts/tarc_scripts.pory"
	callnative SetLossData
# 5 "data/scripts/tarc_scripts.pory"
	fadescreen FADE_TO_BLACK
# 6 "data/scripts/tarc_scripts.pory"
	warpsilent MAP_ENTRANCE, 19, 22
	goto EventScript_Meditate_1


EventScript_Meditate_Text_0:
# 2 "data/scripts/tarc_scripts.pory"
	.string "Do you want to abandon this story?$"
