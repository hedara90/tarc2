MythHub_MapScripts::
	.byte 0

MythHub_Area1::
	warpsilent MAP_AREA1, 10, 10
	end

MythHub_Area2::
	warpsilent MAP_AREA2, 10, 10
	end

MythHub_Area3::
	warpsilent MAP_AREA3, 10, 10
	end

MythHub_Area4::
	warpsilent MAP_AREA4, 10, 10
	end

MythHub_Area5::
	warpsilent MAP_AREA5, 10, 10
	end

MythHub_Area6::
	warpsilent MAP_AREA6, 10, 10
	end

MythHub_Area7::
	warpsilent MAP_AREA7, 10, 10
	end

MythHub_Area8::
	warpsilent MAP_AREA8, 10, 10
	end

MythHub_Area9::
	warpsilent MAP_AREA9, 10, 10
	end

MythHub_Boss::
	msgbox MythHub_TextFinalBoss, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES,
	goto_if_eq VAR_RESULT, NO,
	end

MythHub_BossYes::
	closemessage
	warpsilent MAP_BOSS
	end

MythHub_BossNo::
	closemessage
	applymovement LOCALID_PLAYER, MythHub_ExitBoss
	waitmovement 0
	releaseall
	end

MythHub_ExitBoss::
	walk_down
	step_end


MythHub_TextFinalBoss::
	.string "Beyond lies the final foe.\p"
	.string "Do you want to go through?$"
