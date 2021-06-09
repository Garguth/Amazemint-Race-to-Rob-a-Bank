#include "Engine.h"


void Engine::InitializeWalls()
{

	// new new walls =)
	if (currentlevel == 2)
	{
		rayOBJ.Lines[0].ax = 25;
		rayOBJ.Lines[0].ay = 25;
		rayOBJ.Lines[0].bx = 25;
		rayOBJ.Lines[0].by = 175;

		rayOBJ.Lines[1].ax = 25;
		rayOBJ.Lines[1].ay = 175;
		rayOBJ.Lines[1].bx = 900;// 875;////door
		rayOBJ.Lines[1].by = 175;

		rayOBJ.Lines[2].ax = 900;// 875;////door
		rayOBJ.Lines[2].ay = 175;
		rayOBJ.Lines[2].bx = 725;
		rayOBJ.Lines[2].by = 175;

		rayOBJ.Lines[3].ax = 725;
		rayOBJ.Lines[3].ay = 175;
		rayOBJ.Lines[3].bx = 725;
		rayOBJ.Lines[3].by = 375;

		rayOBJ.Lines[4].ax = 725;
		rayOBJ.Lines[4].ay = 375;
		rayOBJ.Lines[4].bx = 725;
		rayOBJ.Lines[4].by = 325;

		rayOBJ.Lines[5].ax = 725;
		rayOBJ.Lines[5].ay = 325;
		rayOBJ.Lines[5].bx = 175;
		rayOBJ.Lines[5].by = 325;

		rayOBJ.Lines[6].ax = 175;
		rayOBJ.Lines[6].ay = 325;
		rayOBJ.Lines[6].bx = 175;
		rayOBJ.Lines[6].by = 575;

		rayOBJ.Lines[7].ax = 175;
		rayOBJ.Lines[7].ay = 575;
		rayOBJ.Lines[7].bx = 725;
		rayOBJ.Lines[7].by = 575;

		rayOBJ.Lines[8].ax = 725;
		rayOBJ.Lines[8].ay = 575;
		rayOBJ.Lines[8].bx = 725;
		rayOBJ.Lines[8].by = 800;// 775;////door

		rayOBJ.Lines[9].ax = 725;
		rayOBJ.Lines[9].ay = 800;// 775;////door
		rayOBJ.Lines[9].bx = 725;
		rayOBJ.Lines[9].by = 725;

		rayOBJ.Lines[10].ax = 725;
		rayOBJ.Lines[10].ay = 725;
		rayOBJ.Lines[10].bx = 175;
		rayOBJ.Lines[10].by = 725;

		rayOBJ.Lines[11].ax = 175;
		rayOBJ.Lines[11].ay = 725;
		rayOBJ.Lines[11].bx = 175;
		rayOBJ.Lines[11].by = 1075;

		rayOBJ.Lines[12].ax = 175;
		rayOBJ.Lines[12].ay = 1075;
		rayOBJ.Lines[12].bx = 400;// 375;////door
		rayOBJ.Lines[12].by = 1075;

		rayOBJ.Lines[13].ax = 400;// 375;////door
		rayOBJ.Lines[13].ay = 1075;
		rayOBJ.Lines[13].bx = 175;
		rayOBJ.Lines[13].by = 1075;

		rayOBJ.Lines[14].ax = 175;
		rayOBJ.Lines[14].ay = 1075;
		rayOBJ.Lines[14].bx = 175;
		rayOBJ.Lines[14].by = 1475;

		rayOBJ.Lines[15].ax = 175;
		rayOBJ.Lines[15].ay = 1475;
		rayOBJ.Lines[15].bx = 175;
		rayOBJ.Lines[15].by = 725;

		rayOBJ.Lines[16].ax = 175;
		rayOBJ.Lines[16].ay = 725;
		rayOBJ.Lines[16].bx = 725;
		rayOBJ.Lines[16].by = 725;

		rayOBJ.Lines[17].ax = 725;
		rayOBJ.Lines[17].ay = 725;
		rayOBJ.Lines[17].bx = 725;
		rayOBJ.Lines[17].by = 575;

		rayOBJ.Lines[18].ax = 725;
		rayOBJ.Lines[18].ay = 575;
		rayOBJ.Lines[18].bx = 175;
		rayOBJ.Lines[18].by = 575;

		rayOBJ.Lines[19].ax = 175;
		rayOBJ.Lines[19].ay = 575;
		rayOBJ.Lines[19].bx = 175;
		rayOBJ.Lines[19].by = 325;

		rayOBJ.Lines[20].ax = 175;
		rayOBJ.Lines[20].ay = 325;
		rayOBJ.Lines[20].bx = 725;
		rayOBJ.Lines[20].by = 325;

		rayOBJ.Lines[21].ax = 725;
		rayOBJ.Lines[21].ay = 325;
		rayOBJ.Lines[21].bx = 725;
		rayOBJ.Lines[21].by = 175;

		rayOBJ.Lines[22].ax = 725;
		rayOBJ.Lines[22].ay = 175;
		rayOBJ.Lines[22].bx = 25;
		rayOBJ.Lines[22].by = 175;

		rayOBJ.Lines[23].ax = 25;
		rayOBJ.Lines[23].ay = 175;
		rayOBJ.Lines[23].bx = 25;
		rayOBJ.Lines[23].by = 1475;

		rayOBJ.Lines[24].ax = 25;
		rayOBJ.Lines[24].ay = 1475;
		rayOBJ.Lines[24].bx = 725;
		rayOBJ.Lines[24].by = 1475;

		rayOBJ.Lines[25].ax = 725;
		rayOBJ.Lines[25].ay = 1475;
		rayOBJ.Lines[25].bx = 725;
		rayOBJ.Lines[25].by = 1075;

		rayOBJ.Lines[26].ax = 725;
		rayOBJ.Lines[26].ay = 1075;
		rayOBJ.Lines[26].bx = 500;// 525;////door
		rayOBJ.Lines[26].by = 1075;

		rayOBJ.Lines[27].ax = 500;// 525;////door
		rayOBJ.Lines[27].ay = 1075;
		rayOBJ.Lines[27].bx = 725;
		rayOBJ.Lines[27].by = 1075;

		rayOBJ.Lines[28].ax = 725;
		rayOBJ.Lines[28].ay = 1075;
		rayOBJ.Lines[28].bx = 725;
		rayOBJ.Lines[28].by = 900;// 925;////door

		rayOBJ.Lines[29].ax = 725;
		rayOBJ.Lines[29].ay = 900;// 925;////door
		rayOBJ.Lines[29].bx = 725;
		rayOBJ.Lines[29].by = 1075;

		rayOBJ.Lines[30].ax = 725;
		rayOBJ.Lines[30].ay = 1075;
		rayOBJ.Lines[30].bx = 900;// 875;////door
		rayOBJ.Lines[30].by = 1075;

		rayOBJ.Lines[31].ax = 900;// 875;////door
		rayOBJ.Lines[31].ay = 1075;
		rayOBJ.Lines[31].bx = 725;
		rayOBJ.Lines[31].by = 1075;

		rayOBJ.Lines[32].ax = 725;
		rayOBJ.Lines[32].ay = 1075;
		rayOBJ.Lines[32].bx = 725;
		rayOBJ.Lines[32].by = 1475;

		rayOBJ.Lines[33].ax = 725;
		rayOBJ.Lines[33].ay = 1475;
		rayOBJ.Lines[33].bx = 2375;
		rayOBJ.Lines[33].by = 1475;

		rayOBJ.Lines[34].ax = 2375;
		rayOBJ.Lines[34].ay = 1475;
		rayOBJ.Lines[34].bx = 2375;
		rayOBJ.Lines[34].by = 1075;

		rayOBJ.Lines[35].ax = 2375;
		rayOBJ.Lines[35].ay = 1075;
		rayOBJ.Lines[35].bx = 2125;
		rayOBJ.Lines[35].by = 1075;

		rayOBJ.Lines[36].ax = 2125;
		rayOBJ.Lines[36].ay = 1075;
		rayOBJ.Lines[36].bx = 2125;
		rayOBJ.Lines[36].by = 1325;

		rayOBJ.Lines[37].ax = 2125;
		rayOBJ.Lines[37].ay = 1325;
		rayOBJ.Lines[37].bx = 1975;
		rayOBJ.Lines[37].by = 1325;

		rayOBJ.Lines[38].ax = 1975;
		rayOBJ.Lines[38].ay = 1325;
		rayOBJ.Lines[38].bx = 1975;
		rayOBJ.Lines[38].by = 1075;

		rayOBJ.Lines[39].ax = 1975;
		rayOBJ.Lines[39].ay = 1075;
		rayOBJ.Lines[39].bx = 1150;// 1175;////door
		rayOBJ.Lines[39].by = 1075;

		rayOBJ.Lines[40].ax = 1150;// 1175;////door
		rayOBJ.Lines[40].ay = 1075;
		rayOBJ.Lines[40].bx = 1325;
		rayOBJ.Lines[40].by = 1075;

		rayOBJ.Lines[41].ax = 1325;
		rayOBJ.Lines[41].ay = 1075;
		rayOBJ.Lines[41].bx = 1325;
		rayOBJ.Lines[41].by = 900;// 925;////door

		rayOBJ.Lines[42].ax = 1325;
		rayOBJ.Lines[42].ay = 900;// 925;////door
		rayOBJ.Lines[42].bx = 1325;
		rayOBJ.Lines[42].by = 1075;

		rayOBJ.Lines[43].ax = 1325;
		rayOBJ.Lines[43].ay = 1075;
		rayOBJ.Lines[43].bx = 1975;
		rayOBJ.Lines[43].by = 1075;

		rayOBJ.Lines[44].ax = 1975;
		rayOBJ.Lines[44].ay = 1075;
		rayOBJ.Lines[44].bx = 1975;
		rayOBJ.Lines[44].by = 725;

		rayOBJ.Lines[45].ax = 1975;
		rayOBJ.Lines[45].ay = 725;
		rayOBJ.Lines[45].bx = 1325;
		rayOBJ.Lines[45].by = 725;

		rayOBJ.Lines[46].ax = 1325;
		rayOBJ.Lines[46].ay = 725;
		rayOBJ.Lines[46].bx = 1325;
		rayOBJ.Lines[46].by = 800;// 775;////door

		rayOBJ.Lines[47].ax = 1325;
		rayOBJ.Lines[47].ay = 800;// 775;////door
		rayOBJ.Lines[47].bx = 1325;
		rayOBJ.Lines[47].by = 500;// 525;////door

		rayOBJ.Lines[48].ax = 1325;
		rayOBJ.Lines[48].ay = 500;// 525;////door
		rayOBJ.Lines[48].bx = 1325;
		rayOBJ.Lines[48].by = 575;

		rayOBJ.Lines[49].ax = 1325;
		rayOBJ.Lines[49].ay = 575;
		rayOBJ.Lines[49].bx = 1975;
		rayOBJ.Lines[49].by = 575;

		rayOBJ.Lines[50].ax = 1975;
		rayOBJ.Lines[50].ay = 575;
		rayOBJ.Lines[50].bx = 1975;
		rayOBJ.Lines[50].by = 175;

		rayOBJ.Lines[51].ax = 1975;
		rayOBJ.Lines[51].ay = 175;
		rayOBJ.Lines[51].bx = 1325;
		rayOBJ.Lines[51].by = 175;

		rayOBJ.Lines[52].ax = 1325;
		rayOBJ.Lines[52].ay = 175;
		rayOBJ.Lines[52].bx = 1325;
		rayOBJ.Lines[52].by = 400;// 375;////door

		rayOBJ.Lines[53].ax = 1325;
		rayOBJ.Lines[53].ay = 400;// 375;////door
		rayOBJ.Lines[53].bx = 1325;
		rayOBJ.Lines[53].by = 175;

		rayOBJ.Lines[54].ax = 1325;
		rayOBJ.Lines[54].ay = 175;
		rayOBJ.Lines[54].bx = 1150;// 1175;////door
		rayOBJ.Lines[54].by = 175;

		rayOBJ.Lines[55].ax = 1150;// 1175;////door
		rayOBJ.Lines[55].ay = 175;
		rayOBJ.Lines[55].bx = 2125;
		rayOBJ.Lines[55].by = 175;

		rayOBJ.Lines[56].ax = 2125;
		rayOBJ.Lines[56].ay = 175;
		rayOBJ.Lines[56].bx = 2125;
		rayOBJ.Lines[56].by = 1075;

		rayOBJ.Lines[57].ax = 2125;
		rayOBJ.Lines[57].ay = 1075;
		rayOBJ.Lines[57].bx = 2375;
		rayOBJ.Lines[57].by = 1075;

		rayOBJ.Lines[58].ax = 2375;
		rayOBJ.Lines[58].ay = 1075;
		rayOBJ.Lines[58].bx = 2375;
		rayOBJ.Lines[58].by = 25;

		rayOBJ.Lines[59].ax = 2375;
		rayOBJ.Lines[59].ay = 25;
		rayOBJ.Lines[59].bx = 25;
		rayOBJ.Lines[59].by = 25;

	}
	else if (currentlevel == 1)
	{
		rayOBJ.Lines[0].ax = 25;
		rayOBJ.Lines[0].ay = 25;
		rayOBJ.Lines[0].bx = 25;
		rayOBJ.Lines[0].by = 225;

		rayOBJ.Lines[1].ax = 25;
		rayOBJ.Lines[1].ay = 225;
		rayOBJ.Lines[1].bx = 2200;
		rayOBJ.Lines[1].by = 225;

		rayOBJ.Lines[2].ax = 2200;
		rayOBJ.Lines[2].ay = 225;
		rayOBJ.Lines[2].bx = 1525;
		rayOBJ.Lines[2].by = 225;

		rayOBJ.Lines[3].ax = 1525;
		rayOBJ.Lines[3].ay = 225;
		rayOBJ.Lines[3].bx = 1525;
		rayOBJ.Lines[3].by = 925;

		rayOBJ.Lines[4].ax = 1525;
		rayOBJ.Lines[4].ay = 925;
		rayOBJ.Lines[4].bx = 1675;
		rayOBJ.Lines[4].by = 925;

		rayOBJ.Lines[5].ax = 1675;
		rayOBJ.Lines[5].ay = 925;
		rayOBJ.Lines[5].bx = 1675;
		rayOBJ.Lines[5].by = 225;

		rayOBJ.Lines[6].ax = 1675;
		rayOBJ.Lines[6].ay = 225;
		rayOBJ.Lines[6].bx = 375;
		rayOBJ.Lines[6].by = 225;

		rayOBJ.Lines[7].ax = 375;
		rayOBJ.Lines[7].ay = 225;
		rayOBJ.Lines[7].bx = 375;
		rayOBJ.Lines[7].by = 925;

		rayOBJ.Lines[8].ax = 375;
		rayOBJ.Lines[8].ay = 925;
		rayOBJ.Lines[8].bx = 1525;
		rayOBJ.Lines[8].by = 925;

		rayOBJ.Lines[9].ax = 1525;
		rayOBJ.Lines[9].ay = 925;
		rayOBJ.Lines[9].bx = 1525;
		rayOBJ.Lines[9].by = 225;

		rayOBJ.Lines[10].ax = 1525;
		rayOBJ.Lines[10].ay = 225;
		rayOBJ.Lines[10].bx = 25;
		rayOBJ.Lines[10].by = 225;

		rayOBJ.Lines[11].ax = 25;
		rayOBJ.Lines[11].ay = 225;
		rayOBJ.Lines[11].bx = 25;
		rayOBJ.Lines[11].by = 1000;

		rayOBJ.Lines[12].ax = 25;
		rayOBJ.Lines[12].ay = 1000;
		rayOBJ.Lines[12].bx = 250;
		rayOBJ.Lines[12].by = 1000;

		rayOBJ.Lines[38].ax = 250;
		rayOBJ.Lines[38].ay = 1000;
		rayOBJ.Lines[38].bx = 650;
		rayOBJ.Lines[38].by = 1475;

		rayOBJ.Lines[13].ax = 650;
		rayOBJ.Lines[13].ay = 1475;
		rayOBJ.Lines[13].bx = 1650;
		rayOBJ.Lines[13].by = 1475;

		rayOBJ.Lines[14].ax = 1650;
		rayOBJ.Lines[14].ay = 1475;
		rayOBJ.Lines[14].bx = 2375;
		rayOBJ.Lines[14].by = 1100;

		rayOBJ.Lines[15].ax = 2375;
		rayOBJ.Lines[15].ay = 1100;
		rayOBJ.Lines[15].bx = 2375;
		rayOBJ.Lines[15].by = 225;

		rayOBJ.Lines[16].ax = 2375;
		rayOBJ.Lines[16].ay = 225;
		rayOBJ.Lines[16].bx = 2300;
		rayOBJ.Lines[16].by = 225;

		rayOBJ.Lines[17].ax = 2300;
		rayOBJ.Lines[17].ay = 225;
		rayOBJ.Lines[17].bx = 2375;
		rayOBJ.Lines[17].by = 225;

		rayOBJ.Lines[18].ax = 2375;
		rayOBJ.Lines[18].ay = 225;
		rayOBJ.Lines[18].bx = 2375;
		rayOBJ.Lines[18].by = 25;

		rayOBJ.Lines[19].ax = 2375;
		rayOBJ.Lines[19].ay = 25;
		rayOBJ.Lines[19].bx = 25;
		rayOBJ.Lines[19].by = 25;

		rayOBJ.Lines[20].ax = 25;
		rayOBJ.Lines[20].ay = 25;
		rayOBJ.Lines[20].bx = 25;
		rayOBJ.Lines[20].by = 225;

		rayOBJ.Lines[21].ax = 25;
		rayOBJ.Lines[21].ay = 225;
		rayOBJ.Lines[21].bx = 2200;
		rayOBJ.Lines[21].by = 225;

		rayOBJ.Lines[22].ax = 2200;
		rayOBJ.Lines[22].ay = 225;
		rayOBJ.Lines[22].bx = 1675;
		rayOBJ.Lines[22].by = 225;

		rayOBJ.Lines[23].ax = 1675;
		rayOBJ.Lines[23].ay = 225;
		rayOBJ.Lines[23].bx = 1675;
		rayOBJ.Lines[23].by = 925;

		rayOBJ.Lines[24].ax = 1675;
		rayOBJ.Lines[24].ay = 925;
		rayOBJ.Lines[24].bx = 375;
		rayOBJ.Lines[24].by = 925;

		rayOBJ.Lines[25].ax = 375;
		rayOBJ.Lines[25].ay = 925;
		rayOBJ.Lines[25].bx = 375;
		rayOBJ.Lines[25].by = 225;

		rayOBJ.Lines[26].ax = 375;
		rayOBJ.Lines[26].ay = 225;
		rayOBJ.Lines[26].bx = 25;
		rayOBJ.Lines[26].by = 225;

		rayOBJ.Lines[27].ax = 25;
		rayOBJ.Lines[27].ay = 225;
		rayOBJ.Lines[27].bx = 25;
		rayOBJ.Lines[27].by = 25;
		////

		rayOBJ.Lines[28].ax = 525;
		rayOBJ.Lines[28].ay = 15000;
		rayOBJ.Lines[28].bx = 625;
		rayOBJ.Lines[28].by = 15000;

		rayOBJ.Lines[29].ax = 625;
		rayOBJ.Lines[29].ay = 15000;
		rayOBJ.Lines[29].bx = 725;
		rayOBJ.Lines[29].by = 15000;

		rayOBJ.Lines[30].ax = 725;
		rayOBJ.Lines[30].ay = 15000;
		rayOBJ.Lines[30].bx = 825;
		rayOBJ.Lines[30].by = 15000;

		rayOBJ.Lines[31].ax = 825;
		rayOBJ.Lines[31].ay = 15000;
		rayOBJ.Lines[31].bx = 925;
		rayOBJ.Lines[31].by = 15000;

		rayOBJ.Lines[32].ax = 925;
		rayOBJ.Lines[32].ay = 15000;
		rayOBJ.Lines[32].bx = 1025;
		rayOBJ.Lines[32].by = 15000;

		rayOBJ.Lines[33].ax = 1025;
		rayOBJ.Lines[33].ay = 15000;
		rayOBJ.Lines[33].bx = 1125;
		rayOBJ.Lines[33].by = 15000;

		rayOBJ.Lines[34].ax = 1125;
		rayOBJ.Lines[34].ay = 15000;
		rayOBJ.Lines[34].bx = 1225;
		rayOBJ.Lines[34].by = 15000;

		rayOBJ.Lines[35].ax = 1225;
		rayOBJ.Lines[35].ay = 15000;
		rayOBJ.Lines[35].bx = 1325;
		rayOBJ.Lines[35].by = 15000;

		rayOBJ.Lines[36].ax = 1325;
		rayOBJ.Lines[36].ay = 15000;
		rayOBJ.Lines[36].bx = 1425;
		rayOBJ.Lines[36].by = 15000;

		////
		rayOBJ.Lines[37].ax = 1675;
		rayOBJ.Lines[37].ay = 925;
		rayOBJ.Lines[37].bx = 2375;
		rayOBJ.Lines[37].by = 925;

	}



	// new walls =( pliz dont erase me
//	 outside
//	rayOBJ.Lines[0].ax = 0;
//	rayOBJ.Lines[0].ay = 0;
//	rayOBJ.Lines[0].bx = 2350;
//	rayOBJ.Lines[0].by = 0;
//
//	rayOBJ.Lines[1].ax = 2350;
//	rayOBJ.Lines[1].ay = 0;
//	rayOBJ.Lines[1].bx = 2350;
//	rayOBJ.Lines[1].by = 1450;
//
//
//	rayOBJ.Lines[2].ax = 2350;
//	rayOBJ.Lines[2].ay = 1450;
//	rayOBJ.Lines[2].bx = 0;
//	rayOBJ.Lines[2].by = 1450;
//
//	rayOBJ.Lines[3].ax = 0;
//	rayOBJ.Lines[3].ay = 1450;
//	rayOBJ.Lines[3].bx = 0;
//	rayOBJ.Lines[3].by = 0;
//
//	rayOBJ.Lines[4].ax = 0;
//	rayOBJ.Lines[4].ay = 0;
//	rayOBJ.Lines[4].bx = 0;
//	rayOBJ.Lines[4].by = 175;
//	// First wall
//	rayOBJ.Lines[5].ax = 0;
//	rayOBJ.Lines[5].ay = 175;
//	rayOBJ.Lines[5].bx = 2125;
//	rayOBJ.Lines[5].by = 175;
//
//	rayOBJ.Lines[6].ax = 2125;
//	rayOBJ.Lines[6].ay = 175;
//	rayOBJ.Lines[6].bx = 2125;
//	rayOBJ.Lines[6].by = 1325;
//
//	rayOBJ.Lines[7].ax = 2125;
//	rayOBJ.Lines[7].ay = 1325;
//	rayOBJ.Lines[7].bx = 2125;
//	rayOBJ.Lines[7].by = 1075;
//
//	rayOBJ.Lines[8].ax = 2125;
//	rayOBJ.Lines[8].ay = 1075;
//	rayOBJ.Lines[8].bx = 2350;
//	rayOBJ.Lines[8].by = 1075;
//
//	rayOBJ.Lines[9].ax = 2350;
//	rayOBJ.Lines[9].ay = 1075;
//	rayOBJ.Lines[9].bx = 2125;
//	rayOBJ.Lines[9].by = 1075;
//
//	rayOBJ.Lines[10].ax = 2125;
//	rayOBJ.Lines[10].ay = 1075;
//	rayOBJ.Lines[10].bx = 2125;
//	rayOBJ.Lines[10].by = 1325;
//
//	rayOBJ.Lines[11].ax = 2125;
//	rayOBJ.Lines[11].ay = 1325;
//	rayOBJ.Lines[11].bx = 1975;
//	rayOBJ.Lines[11].by = 1325;
//
//	rayOBJ.Lines[12].ax = 1975;
//	rayOBJ.Lines[12].ay = 1325;
//	rayOBJ.Lines[12].bx = 1975;
//	rayOBJ.Lines[12].by = 1075;
//
//
//	rayOBJ.Lines[13].ax = 1975;
//	rayOBJ.Lines[13].ay = 1075;
//	rayOBJ.Lines[13].bx = 175;
//	rayOBJ.Lines[13].by = 1075;
//
//	rayOBJ.Lines[14].ax = 175;
//	rayOBJ.Lines[14].ay = 1075;
//	rayOBJ.Lines[14].bx = 175;
//	rayOBJ.Lines[14].by = 1450;
/////////
//	rayOBJ.Lines[15].ax = 175;
//	rayOBJ.Lines[15].ay = 1450;
//	rayOBJ.Lines[15].bx = 725;
//	rayOBJ.Lines[15].by = 1450;
//
//	rayOBJ.Lines[16].ax = 725;
//	rayOBJ.Lines[16].ay = 1450;
//	rayOBJ.Lines[16].bx = 725;
//	rayOBJ.Lines[16].by = 1075;
//
//	rayOBJ.Lines[17].ax = 725;
//	rayOBJ.Lines[17].ay = 1075;
//	rayOBJ.Lines[17].bx = 725;
//	rayOBJ.Lines[17].by = 775;
//
//	rayOBJ.Lines[18].ax = 725;
//	rayOBJ.Lines[18].ay = 775;
//	rayOBJ.Lines[18].bx = 175;
//	rayOBJ.Lines[18].by = 775;
//
//	rayOBJ.Lines[19].ax = 175;
//	rayOBJ.Lines[19].ay = 775;
//	rayOBJ.Lines[19].bx = 175;
//	rayOBJ.Lines[19].by = 1075;
//
//	rayOBJ.Lines[20].ax = 175;
//	rayOBJ.Lines[20].ay = 1075;
//	rayOBJ.Lines[20].bx = 725;
//	rayOBJ.Lines[20].by = 1075;
//
//	rayOBJ.Lines[21].ax = 725;
//	rayOBJ.Lines[21].ay = 1075;
//	rayOBJ.Lines[21].bx = 725;
//	rayOBJ.Lines[21].by = 525;
//
//	rayOBJ.Lines[22].ax = 725;
//	rayOBJ.Lines[22].ay = 525;
//	rayOBJ.Lines[22].bx = 175;
//	rayOBJ.Lines[22].by = 525;
//
//	rayOBJ.Lines[23].ax = 175;
//	rayOBJ.Lines[23].ay = 525;
//	rayOBJ.Lines[23].bx = 175;
//	rayOBJ.Lines[23].by = 375;
//
//	rayOBJ.Lines[24].ax = 175;
//	rayOBJ.Lines[24].ay = 375;
//	rayOBJ.Lines[24].bx = 725;
//	rayOBJ.Lines[24].by = 375;
//
//	rayOBJ.Lines[25].ax = 175;
//	rayOBJ.Lines[25].ay = 375;
//	rayOBJ.Lines[25].bx = 725;
//	rayOBJ.Lines[25].by = 375;
//
//	rayOBJ.Lines[26].ax = 725;
//	rayOBJ.Lines[26].ay = 375;
//	rayOBJ.Lines[26].bx = 725;
//	rayOBJ.Lines[26].by = 425;
//
//
//	rayOBJ.Lines[27].ax = 725;
//	rayOBJ.Lines[27].ay = 425;
//	rayOBJ.Lines[27].bx = 725;
//	rayOBJ.Lines[27].by = 175;
//
//
//	rayOBJ.Lines[28].ax = 725;
//	rayOBJ.Lines[28].ay = 175;
//	rayOBJ.Lines[28].bx = 1325;
//	rayOBJ.Lines[28].by = 175;
//
//	rayOBJ.Lines[29].ax = 1325;
//	rayOBJ.Lines[29].ay = 175;
//	rayOBJ.Lines[29].bx = 1325;
//	rayOBJ.Lines[29].by = 625;
//
//	rayOBJ.Lines[30].ax = 1325;
//	rayOBJ.Lines[30].ay = 625;
//	rayOBJ.Lines[30].bx = 1975;
//	rayOBJ.Lines[30].by = 625;
//
//	rayOBJ.Lines[31].ax = 1975;
//	rayOBJ.Lines[31].ay = 625;
//	rayOBJ.Lines[31].bx = 1975;
//	rayOBJ.Lines[31].by = 175;
//
//	rayOBJ.Lines[32].ax = 1975;
//	rayOBJ.Lines[32].ay = 175;
//	rayOBJ.Lines[32].bx = 1325;
//	rayOBJ.Lines[32].by = 175;
//
//	rayOBJ.Lines[33].ax = 1325;
//	rayOBJ.Lines[33].ay = 175;
//	rayOBJ.Lines[33].bx = 1325;
//	rayOBJ.Lines[33].by = 1075;
//
//	rayOBJ.Lines[34].ax = 1325;
//	rayOBJ.Lines[34].ay = 1075;
//	rayOBJ.Lines[34].bx = 1975;
//	rayOBJ.Lines[34].by = 1075;
//
//	rayOBJ.Lines[35].ax = 1975;
//	rayOBJ.Lines[35].ay = 1075;
//	rayOBJ.Lines[35].bx = 1975;
//	rayOBJ.Lines[35].by = 775;
//
//	rayOBJ.Lines[36].ax = 1975;
//	rayOBJ.Lines[36].ay = 775;
//	rayOBJ.Lines[36].bx = 1325;
//	rayOBJ.Lines[36].by = 775;
//
//	rayOBJ.Lines[37].ax = 1325;
//	rayOBJ.Lines[37].ay = 775;
//	rayOBJ.Lines[37].bx = 1325;
//	rayOBJ.Lines[37].by = 175;
//
//	rayOBJ.Lines[38].ax = 1325;
//	rayOBJ.Lines[38].ay = 175;
//	rayOBJ.Lines[38].bx = 0;
//	rayOBJ.Lines[38].by = 175;
//
//	rayOBJ.Lines[39].ax = 0;
//	rayOBJ.Lines[39].ay = 175;
//	rayOBJ.Lines[39].bx = 0;
//	rayOBJ.Lines[39].by = 0;
//	outside walls

//	rayOBJ.Lines[1].ax = 50;
//	rayOBJ.Lines[1].ay = 50;
//	rayOBJ.Lines[1].bx = 50;
//	rayOBJ.Lines[1].by = 1450;
//
//	rayOBJ.Lines[2].ax = 50;
//	rayOBJ.Lines[2].ay = 1450;
//	rayOBJ.Lines[2].bx = 2350;
//	rayOBJ.Lines[2].by = 1450;
//
//
//	//
//
//	rayOBJ.Lines[4].ax = 50;
//	rayOBJ.Lines[4].ay = 150;
//	rayOBJ.Lines[4].bx = 900;
//	rayOBJ.Lines[4].by = 150;
//
//	rayOBJ.Lines[5].ax = 900;
//	rayOBJ.Lines[5].ay = 150;
//	rayOBJ.Lines[5].bx = 900;
//	rayOBJ.Lines[5].by = 200;
//
//	rayOBJ.Lines[6].ax = 900;
//	rayOBJ.Lines[6].ay = 200;
//	rayOBJ.Lines[6].bx = 50;
//	rayOBJ.Lines[6].by = 200;
//
//	rayOBJ.Lines[7].ax = 50;
//	rayOBJ.Lines[7].ay = 200;
//	rayOBJ.Lines[7].bx = 50;
//	rayOBJ.Lines[7].by = 1450;
//
//	rayOBJ.Lines[8].ax = 700;
//	rayOBJ.Lines[8].ay = 1450;
//	rayOBJ.Lines[8].bx = 700;
//	rayOBJ.Lines[8].by = 1100;
//
//	rayOBJ.Lines[9].ax = 700;
//	rayOBJ.Lines[9].ay = 1100;
//	rayOBJ.Lines[9].bx = 500;
//	rayOBJ.Lines[9].by = 1100;
//
//	rayOBJ.Lines[10].ax = 500;
//	rayOBJ.Lines[10].ay = 1100;
//	rayOBJ.Lines[10].bx = 500;
//	rayOBJ.Lines[10].by = 1050;
//		
//	rayOBJ.Lines[11].ax = 500;
//	rayOBJ.Lines[11].ay = 1050;
//	rayOBJ.Lines[11].bx = 700;
//	rayOBJ.Lines[11].by = 1050;
//
//	rayOBJ.Lines[12].ax = 700;
//	rayOBJ.Lines[12].ay = 1050;
//	rayOBJ.Lines[12].bx = 700;
//	rayOBJ.Lines[12].by = 900;
//	
//	rayOBJ.Lines[13].ax = 700;
//	rayOBJ.Lines[13].ay = 900;
//	rayOBJ.Lines[13].bx = 750;
//	rayOBJ.Lines[13].by = 900;
//
//	rayOBJ.Lines[14].ax = 750;
//	rayOBJ.Lines[14].ay = 900;
//	rayOBJ.Lines[14].bx = 750;
//	rayOBJ.Lines[14].by = 1050;
//
//	rayOBJ.Lines[15].ax = 750;
//	rayOBJ.Lines[15].ay = 1050;
//	rayOBJ.Lines[15].bx = 900;
//	rayOBJ.Lines[15].by = 1050;
//
//	rayOBJ.Lines[16].ax = 900;
//	rayOBJ.Lines[16].ay = 1050;
//	rayOBJ.Lines[16].bx = 900;
//	rayOBJ.Lines[16].by = 1100;
//
//	rayOBJ.Lines[17].ax = 900;
//	rayOBJ.Lines[17].ay = 1100;
//	rayOBJ.Lines[17].bx = 750;
//	rayOBJ.Lines[17].by = 1100;
//
//	rayOBJ.Lines[18].ax = 750;
//	rayOBJ.Lines[18].ay = 1100;
//	rayOBJ.Lines[18].bx = 750;
//	rayOBJ.Lines[18].by = 1450;
//
//	////
//	rayOBJ.Lines[19].ax = 2350;//diego
//	rayOBJ.Lines[3].ay = 1450;
//	rayOBJ.Lines[3].bx = 2350;
//	rayOBJ.Lines[3].by = 50;
//
//	rayOBJ.Lines[97].ax = 2350;
//	rayOBJ.Lines[97].ay = 50;
//	rayOBJ.Lines[97].bx = 50;
//	rayOBJ.Lines[97].by = 50;
//
//	rayOBJ.Lines[0].ax = 50;
//	rayOBJ.Lines[0].ay = 50;
//	rayOBJ.Lines[0].bx = 50;
//	rayOBJ.Lines[0].by = 150;
//
//	rayOBJ.Lines[4].ax = 50;
//	rayOBJ.Lines[4].ay = 150;
//	rayOBJ.Lines[4].bx = 900;
//	rayOBJ.Lines[4].by = 150;
//
//	rayOBJ.Lines[5].ax = 900;
//	rayOBJ.Lines[5].ay = 150;
//	rayOBJ.Lines[5].bx = 900;
//	rayOBJ.Lines[5].by = 200;
//
//	rayOBJ.Lines[6].ax = 900;
//	rayOBJ.Lines[6].ay = 200;
//	rayOBJ.Lines[6].bx = 700;
//	rayOBJ.Lines[6].by = 200;
//
//
//
//	rayOBJ.Lines[19].ax = 1000;
//	rayOBJ.Lines[19].ay = 150;
//	rayOBJ.Lines[19].bx = 1050;
//	rayOBJ.Lines[19].by = 150;
//
//	rayOBJ.Lines[20].ax = 1000;
//	rayOBJ.Lines[20].ay = 150;
//	rayOBJ.Lines[20].bx = 1000;
//	rayOBJ.Lines[20].by = 200;
//
//	rayOBJ.Lines[21].ax = 1000;
//	rayOBJ.Lines[21].ay = 200;
//	rayOBJ.Lines[21].bx = 1050;
//	rayOBJ.Lines[21].by = 200;
//
//	rayOBJ.Lines[22].ax = 1050;
//	rayOBJ.Lines[22].ay = 150;
//	rayOBJ.Lines[22].bx = 1050;
//	rayOBJ.Lines[22].by = 200;
//
//	rayOBJ.Lines[23].ax = 1150;
//	rayOBJ.Lines[23].ay = 150;
//	rayOBJ.Lines[23].bx = 2150;
//	rayOBJ.Lines[23].by = 150;
//
//	rayOBJ.Lines[24].ax = 1150;
//	rayOBJ.Lines[24].ay = 150;
//	rayOBJ.Lines[24].bx = 1150;
//	rayOBJ.Lines[24].by = 200;
//
//	rayOBJ.Lines[25].ax = 1300;
//	rayOBJ.Lines[25].ay = 200;
//	rayOBJ.Lines[25].bx = 1300;
//	rayOBJ.Lines[25].by = 400;
//
//	rayOBJ.Lines[26].ax = 1300;
//	rayOBJ.Lines[26].ay = 400;
//	rayOBJ.Lines[26].bx = 1350;
//	rayOBJ.Lines[26].by = 400;
//
//	rayOBJ.Lines[27].ax = 1350;
//	rayOBJ.Lines[27].ay = 400;
//	rayOBJ.Lines[27].bx = 1350;
//	rayOBJ.Lines[27].by = 200;
//
//	rayOBJ.Lines[28].ax = 1350;
//	rayOBJ.Lines[28].ay = 200;
//	rayOBJ.Lines[28].bx = 2100;
//	rayOBJ.Lines[28].by = 200;
//
//	rayOBJ.Lines[29].ax = 1950;
//	rayOBJ.Lines[29].ay = 300;
//	rayOBJ.Lines[29].bx = 1950;
//	rayOBJ.Lines[29].by = 550;
//
//	rayOBJ.Lines[30].ax = 1950;
//	rayOBJ.Lines[30].ay = 550;
//	rayOBJ.Lines[30].bx = 1350;
//	rayOBJ.Lines[30].by = 550;
//
//	rayOBJ.Lines[31].ax = 1350;
//	rayOBJ.Lines[31].ay = 550;
//	rayOBJ.Lines[31].bx = 1350;
//	rayOBJ.Lines[31].by = 500;
//
//	rayOBJ.Lines[32].ax = 1350;
//	rayOBJ.Lines[32].ay = 500;
//	rayOBJ.Lines[32].bx = 1300;
//	rayOBJ.Lines[32].by = 500;
//
//	rayOBJ.Lines[33].ax = 1300;
//	rayOBJ.Lines[33].ay = 500;
//	rayOBJ.Lines[33].bx = 1300;
//	rayOBJ.Lines[33].by = 800;
//
//	rayOBJ.Lines[34].ax = 1300;
//	rayOBJ.Lines[34].ay = 800;
//	rayOBJ.Lines[34].bx = 1350;
//	rayOBJ.Lines[34].by = 800;
//
//	rayOBJ.Lines[35].ax = 1350;
//	rayOBJ.Lines[35].ay = 800;
//	rayOBJ.Lines[35].bx = 1350;
//	rayOBJ.Lines[35].by = 600;
//
//	rayOBJ.Lines[36].ax = 1450;
//	rayOBJ.Lines[36].ay = 750;
//	rayOBJ.Lines[36].bx = 1950;
//	rayOBJ.Lines[36].by = 750;
//
//	rayOBJ.Lines[37].ax = 1950;
//	rayOBJ.Lines[37].ay = 750;
//	rayOBJ.Lines[37].bx = 1950;
//	rayOBJ.Lines[37].by = 1050;
//
//	rayOBJ.Lines[38].ax = 1950;
//	rayOBJ.Lines[38].ay = 1050;
//	rayOBJ.Lines[38].bx = 1350;
//	rayOBJ.Lines[38].by = 1050;
//
//	rayOBJ.Lines[39].ax = 1350;
//	rayOBJ.Lines[39].ay = 1050;
//	rayOBJ.Lines[39].bx = 1350;
//	rayOBJ.Lines[39].by = 900;
//
//	rayOBJ.Lines[40].ax = 1350;
//	rayOBJ.Lines[40].ay = 900;
//	rayOBJ.Lines[40].bx = 1300;
//	rayOBJ.Lines[40].by = 900;
//
//	rayOBJ.Lines[41].ax = 1300;
//	rayOBJ.Lines[41].ay = 900;
//	rayOBJ.Lines[41].bx = 1300;
//	rayOBJ.Lines[41].by = 1050;
//
//	rayOBJ.Lines[42].ax = 1300;
//	rayOBJ.Lines[42].ay = 1050;
//	rayOBJ.Lines[42].bx = 1150;
//	rayOBJ.Lines[42].by = 1050;
//
//	rayOBJ.Lines[43].ax = 1150;
//	rayOBJ.Lines[43].ay = 1050;
//	rayOBJ.Lines[43].bx = 1150;
//	rayOBJ.Lines[43].by = 1100;
//
//	rayOBJ.Lines[44].ax = 1150;
//	rayOBJ.Lines[44].ay = 1100;
//	rayOBJ.Lines[44].bx = 1950;
//	rayOBJ.Lines[44].by = 1100;
//
//	rayOBJ.Lines[45].ax = 1950;
//	rayOBJ.Lines[45].ay = 1100;
//	rayOBJ.Lines[45].bx = 1950;
//	rayOBJ.Lines[45].by = 1200;
//
//	rayOBJ.Lines[46].ax = 200;
//	rayOBJ.Lines[46].ay = 1350;
//	rayOBJ.Lines[46].bx = 150;
//	rayOBJ.Lines[46].by = 1350;
//
//	rayOBJ.Lines[47].ax = 150;
//	rayOBJ.Lines[47].ay = 1350;
//	rayOBJ.Lines[47].bx = 150;
//	rayOBJ.Lines[47].by = 700;
//
//	rayOBJ.Lines[48].ax = 150;
//	rayOBJ.Lines[48].ay = 700;
//	rayOBJ.Lines[48].bx = 600;
//	rayOBJ.Lines[48].by = 700;
//
//	rayOBJ.Lines[49].ax = 600;
//	rayOBJ.Lines[49].ay = 700;
//	rayOBJ.Lines[49].bx = 600;
//	rayOBJ.Lines[49].by = 750;
//
//	rayOBJ.Lines[50].ax = 600;
//	rayOBJ.Lines[50].ay = 750;
//	rayOBJ.Lines[50].bx = 200;
//	rayOBJ.Lines[50].by = 750;
//
//	rayOBJ.Lines[51].ax = 200;
//	rayOBJ.Lines[51].ay = 750;
//	rayOBJ.Lines[51].bx = 200;
//	rayOBJ.Lines[51].by = 1050;
//
//	rayOBJ.Lines[52].ax = 200;
//	rayOBJ.Lines[52].ay = 1050;
//	rayOBJ.Lines[52].bx = 400;
//	rayOBJ.Lines[52].by = 1050;
//
//	rayOBJ.Lines[53].ax = 400;
//	rayOBJ.Lines[53].ay = 1050;
//	rayOBJ.Lines[53].bx = 400;
//	rayOBJ.Lines[53].by = 1100;
//
//	rayOBJ.Lines[54].ax = 400;
//	rayOBJ.Lines[54].ay = 1100;
//	rayOBJ.Lines[54].bx = 200;
//	rayOBJ.Lines[54].by = 1100;
//
//	rayOBJ.Lines[55].ax = 200;
//	rayOBJ.Lines[55].ay = 1100;
//	rayOBJ.Lines[55].bx = 200;
//	rayOBJ.Lines[55].by = 1350;
//
//	rayOBJ.Lines[56].ax = 200;
//	rayOBJ.Lines[56].ay = 350;
//	rayOBJ.Lines[56].bx = 200;
//	rayOBJ.Lines[56].by = 600;
//
//	////
//
//
//	rayOBJ.Lines[57].ax = 1950;
//	rayOBJ.Lines[57].ay = 1300;
//	rayOBJ.Lines[57].bx = 1950;
//	rayOBJ.Lines[57].by = 1350;
//
//	rayOBJ.Lines[58].ax = 1950;
//	rayOBJ.Lines[58].ay = 1350;
//	rayOBJ.Lines[58].bx = 2150;
//	rayOBJ.Lines[58].by = 1350;
//
//	rayOBJ.Lines[59].ax = 2150;
//	rayOBJ.Lines[59].ay = 1350;
//	rayOBJ.Lines[59].bx = 2150;
//	rayOBJ.Lines[59].by = 1200;
//
//	rayOBJ.Lines[60].ax = 2100;
//	rayOBJ.Lines[60].ay = 1100;
//	rayOBJ.Lines[60].bx = 2200;
//	rayOBJ.Lines[60].by = 1100;
//
//	rayOBJ.Lines[61].ax = 2200;
//	rayOBJ.Lines[61].ay = 1100;
//	rayOBJ.Lines[61].bx = 2200;
//	rayOBJ.Lines[61].by = 1050;
//
//	rayOBJ.Lines[62].ax = 2200;
//	rayOBJ.Lines[62].ay = 1050;
//	rayOBJ.Lines[62].bx = 2150;
//	rayOBJ.Lines[62].by = 1050;
//
//	rayOBJ.Lines[63].ax = 2150;
//	rayOBJ.Lines[63].ay = 1050;
//	rayOBJ.Lines[63].bx = 2150;
//	rayOBJ.Lines[63].by = 550;
//
//	rayOBJ.Lines[64].ax = 2150;
//	rayOBJ.Lines[64].ay = 450;
//	rayOBJ.Lines[64].bx = 2150;
//	rayOBJ.Lines[64].by = 150;
//
//	rayOBJ.Lines[65].ax = 2350;
//	rayOBJ.Lines[65].ay = 1050;
//	rayOBJ.Lines[65].bx = 2300;
//	rayOBJ.Lines[65].by = 1050;
//
//	rayOBJ.Lines[66].ax = 2300;
//	rayOBJ.Lines[66].ay = 1050;
//	rayOBJ.Lines[66].bx = 2300;
//	rayOBJ.Lines[66].by = 1100;
//
//	rayOBJ.Lines[67].ax = 2300;
//	rayOBJ.Lines[67].ay = 1100;
//	rayOBJ.Lines[67].bx = 2350;
//	rayOBJ.Lines[67].by = 1100;
//
//	rayOBJ.Lines[68].ax = 2100;
//	rayOBJ.Lines[68].ay = 200;
//	rayOBJ.Lines[68].bx = 2100;
//	rayOBJ.Lines[68].by = 450;
//
//	rayOBJ.Lines[69].ax = 2100;
//	rayOBJ.Lines[69].ay = 450;
//	rayOBJ.Lines[69].bx = 2150;
//	rayOBJ.Lines[69].by = 450;
//
//	rayOBJ.Lines[70].ax = 2150;
//	rayOBJ.Lines[70].ay = 550;
//	rayOBJ.Lines[70].bx = 2100;
//	rayOBJ.Lines[70].by = 550;
//
//	rayOBJ.Lines[71].ax = 2100;
//	rayOBJ.Lines[71].ay = 550;
//	rayOBJ.Lines[71].bx = 2100;
//	rayOBJ.Lines[71].by = 1100;
//
//	rayOBJ.Lines[72].ax = 2150;
//	rayOBJ.Lines[72].ay = 1200;
//	rayOBJ.Lines[72].bx = 2100;
//	rayOBJ.Lines[72].by = 1200;
//
//	rayOBJ.Lines[73].ax = 2100;
//	rayOBJ.Lines[73].ay = 1200;
//	rayOBJ.Lines[73].bx = 2100;
//	rayOBJ.Lines[73].by = 1300;
//
//	rayOBJ.Lines[74].ax = 1950;
//	rayOBJ.Lines[74].ay = 1200;
//	rayOBJ.Lines[74].bx = 2000;
//	rayOBJ.Lines[74].by = 1200;
//
//	rayOBJ.Lines[75].ax = 2000;
//	rayOBJ.Lines[75].ay = 1200;
//	rayOBJ.Lines[75].bx = 2000;
//	rayOBJ.Lines[75].by = 700;
//
//	rayOBJ.Lines[76].ax = 2000;
//	rayOBJ.Lines[76].ay = 700;
//	rayOBJ.Lines[76].bx = 1450;
//	rayOBJ.Lines[76].by = 700;
//
//	rayOBJ.Lines[77].ax = 1450;
//	rayOBJ.Lines[77].ay = 700;
//	rayOBJ.Lines[77].bx = 1450;
//	rayOBJ.Lines[77].by = 750;
//
//	rayOBJ.Lines[78].ax = 1350;
//	rayOBJ.Lines[78].ay = 600;
//	rayOBJ.Lines[78].bx = 2000;
//	rayOBJ.Lines[78].by = 600;
//
//	rayOBJ.Lines[79].ax = 2000;
//	rayOBJ.Lines[79].ay = 600;
//	rayOBJ.Lines[79].bx = 2000;
//	rayOBJ.Lines[79].by = 300;
//
//	rayOBJ.Lines[80].ax = 2000;
//	rayOBJ.Lines[80].ay = 300;
//	rayOBJ.Lines[80].bx = 1950;
//	rayOBJ.Lines[80].by = 300;
//
//	rayOBJ.Lines[81].ax = 1000;
//	rayOBJ.Lines[81].ay = 1050;
//	rayOBJ.Lines[81].bx = 1050;
//	rayOBJ.Lines[81].by = 1050;
//
//	rayOBJ.Lines[82].ax = 1050;
//	rayOBJ.Lines[82].ay = 1050;
//	rayOBJ.Lines[82].bx = 1050;
//	rayOBJ.Lines[82].by = 1100;
//
//	rayOBJ.Lines[83].ax = 1050;
//	rayOBJ.Lines[83].ay = 1100;
//	rayOBJ.Lines[83].bx = 1000;
//	rayOBJ.Lines[83].by = 1100;
//
//	rayOBJ.Lines[84].ax = 1000;
//	rayOBJ.Lines[84].ay = 1100;
//	rayOBJ.Lines[84].bx = 1000;
//	rayOBJ.Lines[84].by = 1050;
//
//////
//
//	rayOBJ.Lines[85].ax = 200;
//	rayOBJ.Lines[85].ay = 350;
//	rayOBJ.Lines[85].bx = 200;
//	rayOBJ.Lines[85].by = 550;
//
//	rayOBJ.Lines[86].ax = 200;
//	rayOBJ.Lines[86].ay = 550;
//	rayOBJ.Lines[86].bx = 750;
//	rayOBJ.Lines[86].by = 550;
//
//	rayOBJ.Lines[87].ax = 750;
//	rayOBJ.Lines[87].ay = 550;
//	rayOBJ.Lines[87].bx = 750;
//	rayOBJ.Lines[87].by = 800;
//
//	rayOBJ.Lines[88].ax = 750;
//	rayOBJ.Lines[88].ay = 800;
//	rayOBJ.Lines[88].bx = 700;
//	rayOBJ.Lines[88].by = 800;
//
//	rayOBJ.Lines[89].ax = 700;
//	rayOBJ.Lines[89].ay = 800;
//	rayOBJ.Lines[89].bx = 700;
//	rayOBJ.Lines[89].by = 600;
//
//	rayOBJ.Lines[90].ax = 700;
//	rayOBJ.Lines[90].ay = 600;
//	rayOBJ.Lines[90].bx = 150;
//	rayOBJ.Lines[90].by = 600;
//
//	rayOBJ.Lines[91].ax = 150;
//	rayOBJ.Lines[91].ay = 600;
//	rayOBJ.Lines[91].bx = 150;
//	rayOBJ.Lines[91].by = 300;
//
//	rayOBJ.Lines[92].ax = 150;
//	rayOBJ.Lines[92].ay = 300;
//	rayOBJ.Lines[92].bx = 750;
//	rayOBJ.Lines[92].by = 300;
//
//	rayOBJ.Lines[93].ax = 750;
//	rayOBJ.Lines[93].ay = 300;
//	rayOBJ.Lines[93].bx = 750;
//	rayOBJ.Lines[93].by = 400;
//
//	rayOBJ.Lines[94].ax = 750;
//	rayOBJ.Lines[94].ay = 400;
//	rayOBJ.Lines[94].bx = 700;
//	rayOBJ.Lines[94].by = 400;
//
//	rayOBJ.Lines[95].ax = 700;
//	rayOBJ.Lines[95].ay = 400;
//	rayOBJ.Lines[95].bx = 700;
//	rayOBJ.Lines[95].by = 350;
//
//	rayOBJ.Lines[96].ax = 700;
//	rayOBJ.Lines[96].ay = 350;
//	rayOBJ.Lines[96].bx = 200;
//	rayOBJ.Lines[96].by = 350;
//
//
//
//	rayOBJ.Lines[98].ax = 0;
//	rayOBJ.Lines[98].ay = 0;
//	rayOBJ.Lines[98].bx = 0;
//	rayOBJ.Lines[98].by = 1450;
//	

}