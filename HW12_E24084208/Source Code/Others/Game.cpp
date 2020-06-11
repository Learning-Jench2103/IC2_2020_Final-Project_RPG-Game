#include "Game.h"
#include <conio.h>
#include <ctime>
#include <set>
#include <fstream>

using namespace std;

void Game::generatePlayers()
{
	Menu player_select_menu;
	{
		player_select_menu.question_name = "請選擇一個角色";

		player_select_menu.instruction.push_back("您可以只擁有一個角色，並以他傲視群雄");
		player_select_menu.instruction.push_back("您也可以擁有由數個成員組成的戰隊，並和他們一同稱霸天下");
		player_select_menu.instruction.push_back("");
		player_select_menu.instruction.push_back("以下是可選擇的角色清單及他們分別的屬性");
		player_select_menu.instruction.push_back("請以↑↓鍵及 Enter 選擇最想要的職業");
		player_select_menu.instruction.push_back("選擇完畢請按 Esc 退出選單");

		player_select_menu.options.push_back(" NovicePlayer ");
		player_select_menu.options.push_back("  OrcPlayer   ");
		player_select_menu.options.push_back(" KnightPlayer ");
		player_select_menu.options.push_back("MagicianPlayer");

		player_select_menu.option_descriptions.push_back("沒有過多特殊技能讓它無比單純；純真的特質讓對手往往對他掉以輕心，而受到較少的攻擊");
		player_select_menu.option_descriptions.push_back("比 NovicePlayer 擁有更強攻擊能力，卻也讓對手們意識到他的厲害，下手漸漸不留情面");
		player_select_menu.option_descriptions.push_back("擁有將魔力轉換為血量的特殊技能，讓它在千鈞一髮之際往往能有驚無險脫身");
		player_select_menu.option_descriptions.push_back("使用特技可將血量轉為魔力，能在佔到上風時直接給對手更強力的致命一擊");
	}

	int response;
	bool at_least_one = false;
	do {
		NovicePlayer* player_ptr;
		system("cls");
		response = player_select_menu.run();
		switch (response) {
		case 0:
			player_ptr = new NovicePlayer;
			break;
		case 1:
			player_ptr = new OrcPlayer;
			break;
		case 2:
			player_ptr = new KnightPlayer;
			break;
		case 3:
			player_ptr = new MagicianPlayer;
			break;
		default:
			player_ptr = new NovicePlayer;
		}
		if (response != -1) {
			cout << "     為他取個名字吧：";
			string input;
			getline(cin, input);
			player_ptr->setName(input);
			player_list.push_back(player_ptr);
			at_least_one = true;
		}
		else if (!at_least_one) {
			cout << "     您的隊伍至少需要一個職業哦哦哦";
			Sleep(1000);
			system("cls");
			Sleep(500);
		}
	} while (response != -1 || !at_least_one);

	all_player_level_sigma = player_list.size();
}

void Game::initializeFirstFloor()
{
	if (First_floor != nullptr) {
		delete First_floor;
	}
	First_floor = new Field("1F GP教室.csv", 14, 14);
	First_floor->setGrid(111, "陷阱", "●", 253, "");
	First_floor->setGrid(131, "紙條", "■", 250, "");
	First_floor->setGrid(121, "蟲洞", "■", 250, "");
	First_floor->setGrid(11, "商店", "■", 249, "");
	First_floor->setGrid(101, "", "■", 206, "");
}

void Game::initializeSecondFloor()
{
	if (Second_floor != nullptr) {
		delete Second_floor;
	}
	Second_floor = new Field("2F LSD廣場.csv", 14, 14);
	Second_floor->setGrid(11, "商店", "■", 249, "");
	Second_floor->setGrid(201, "", "■", 206, "");
	Second_floor->setGrid(221, "", "■", 242, "Q：最健忘的水果");
	Second_floor->setGrid(222, "", "■", 242, "Q：視力最差的水果");
	Second_floor->setGrid(223, "", "■", 242, "Q：長腳尖嘴郎 吹簫入洞房 只為貪吃硃砂酒 一聲霹靂見閻王");
	Second_floor->setGrid(224, "", "■", 242, "Q：背板過海 滿腹文章");
	Second_floor->setGrid(231, "", "榴", 165, "");
	Second_floor->setGrid(232, "", "槤", 165, "");
	Second_floor->setGrid(233, "", "梨", 165, "");
	Second_floor->setGrid(234, "", "子", 165, "");
	Second_floor->setGrid(235, "", "香", 165, "");
	Second_floor->setGrid(236, "", "蕉", 165, "");
	Second_floor->setGrid(237, "", "芒", 165, "");
	Second_floor->setGrid(238, "", "果", 165, "");
	Second_floor->setGrid(239, "", "西", 165, "");
	Second_floor->setGrid(240, "", "瓜", 165, "");
	Second_floor->setGrid(241, "", "蚊", 165, "");
	Second_floor->setGrid(242, "", "子", 165, "");
	Second_floor->setGrid(243, "", "水", 165, "");
	Second_floor->setGrid(244, "", "蛭", 165, "");
	Second_floor->setGrid(245, "", "烏", 165, "");
	Second_floor->setGrid(246, "", "賊", 165, "");
	Second_floor->setGrid(247, "", "蝸", 165, "");
	Second_floor->setGrid(248, "", "牛", 165, "");
	Second_floor->setGrid(261, "NotNot", "★", 156, "");
	Second_floor->setGrid(262, "NotNot", "★", 156, "");
	Second_floor->setGrid(271, "", "■", 250, "");
}

void Game::initializeThirdFloor()
{
	if (Third_floor != nullptr) {
		delete Third_floor;
	}
	Third_floor = new Field("3F ICCPP World.csv", 15, 11);
	Third_floor->setGrid(11, "商店", "■", 249, "");
	Third_floor->setGrid(301, "", "■", 206, "");
	Third_floor->setGrid(311, "", "●", 165, "");
	Third_floor->setGrid(312, "", "●", 165, "");
	Third_floor->setGrid(313, "", "●", 165, "");
	Third_floor->setGrid(314, "", "●", 165, "");
	Third_floor->setGrid(315, "", "●", 165, "");
}

void Game::setCursor(int x, int y) const
{
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);

	pos.X = x, pos.Y = y;	// 將位置設在 (x,y) 之地方。
	SetConsoleCursorPosition(hin, pos);
}

void Game::setColor(unsigned int color) const
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

bool Game::play()
{
	int press;
	bool game_end = false;

	while (!game_end) {
		system("cls");
		current_field->display();

		if (current_field == First_floor) {
			cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
		}

		// random gift begin
		{
			setColor(12);
			if (step_count > 30 && rand() % 40 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->addExp(10);
				}
				cout << "  恭喜踩到寶箱！你的每位成員都獲得了10點經驗值！\n\n  ";
				setColor();
				step_count = 0;
			}
			else if (step_count > 30 && rand() % 30 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->addHp(5);
				}
				cout << "  恭喜踩到寶箱！你的每位成員都獲得了5點血量！\n\n  ";
				setColor();
				step_count = 0;
			}
			else if (step_count > 30 && rand() % 26 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->addExp(5);
				}
				cout << "  恭喜踩到寶箱！你的每位成員都獲得了5點經驗值！\n\n  ";
				setColor();
				step_count = 0;
			}
			else if (step_count > 30 && rand() % 22 == 0) {
				for (int i = 0; i < player_list.size(); i++) {
					money += 10;
				}
				cout << "  恭喜踩到寶箱！你獲得了10塊金幣！\n\n  ";
				setColor();
				step_count = 0;
			}
			setColor();
		}
		// random gift end

		// detect current_symbol before moving
		set<int> choose_member;

		int current_symbol = current_field->getSymbol();
		{
			// All map
			switch (current_symbol) {
			case 11:
			{
				system("cls");
				store->run();
				system("cls");
				current_field->display();
				if (current_field == First_floor) {
					cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
				}
			}
			break;
			case 21:
			{
				if (rand() % 100 == 0) {
					system("cls");
					cout << "  恭喜您在這個不起眼的角落\n";	Sleep(1000);
					cout << "  遇上了千年一遇的\n";	Sleep(1000);
					cout << "  cpsoo先生走失的那隻\n";	Sleep(1000);
					cout << "  每十多年才會現身一次的那隻\n";	Sleep(1000);
					cout << "  名為薛丁葛格的貓\n\n";	Sleep(1000);
					cout << "  為了感謝你讓牠再次被世人憶起\n";	Sleep(1000);
					cout << "  cpsoo先生決定破天荒\n";	Sleep(1000);
					cout << "  替你所有的隊員祈禱\n";	Sleep(1000);
					cout << "  立即晉升一個等級!!\n\n";
					for (int i = 0; i < player_list.size(); i++) {
						player_list.at(i)->setExp(player_list.at(i)->getLvupExp() + 10);
					}
					Sleep(4000);
					system("cls");
					current_field->display();
					if (current_field == First_floor) {
						cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
					}
				}
			}
			break;
			}

			// 1F 
			switch (current_symbol) {
			case 101:
				if (!goblin_monster_killed) {
					system("cls");
					Sleep(1000);
					cout << "\n  Goblin：你還沒\n\n";
					Sleep(2000);
					cout << "  Goblin：從我身上踩過去\n\n";
					Sleep(2000);
					cout << "  Goblin：還想離開這裡啊啊啊\n\n";
					Sleep(2000);
					cout << "  Goblin：先來我家打敗我再說!!\n\n";
					Sleep(2500);
					system("cls");
					Sleep(1000);
					current_field->display();
					if (current_field == First_floor) {
						cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
					}
				}
				else if (paper_amount < 5) {
					system("cls");
					Sleep(1000);
					cout << "\n  cpsoo先生：Wait wait wait!!\n\n";
					Sleep(2000);
					cout << "  cpsoo先生：我的紙片\n\n";
					Sleep(2000);
					cout << "  cpsoo先生：你還沒找完rrrrrrr\n\n";
					Sleep(2000);
					cout << "  cpsoo先生：撿完前別想離開這裡！\n\n";
					Sleep(2500);
					system("cls");
					Sleep(1000);
					current_field->display();
					if (current_field == First_floor) {
						cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
					}
				}
				else {
					system("cls");
					Sleep(500);
					setCursor(3, 3);
					cout << "電梯上樓...";
					Sleep(1000);
					current_field = Second_floor;
					system("cls");
					if (!second_floor_entered) {
						Welcome_2F welcome;
						welcome.run();
						system("cls");
						Sleep(500);
						second_floor_entered = true;
					}
					current_field->display();
					if (current_field == First_floor) {
						cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
					}
				}
				break;
			case 111:
				// Create a battle
				player_screen = new Menu;
				int player_list_response;
				player_screen->question_name = "查看您的隊伍成員";
				player_screen->instruction.push_back("請以↑↓鍵移動游標，並以Enter選擇參加戰鬥的隊員，選擇完畢請按下Esc；或直接按Esc鍵退出");
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->options.push_back(player_list.at(i)->getName());
				}
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
				}
				//Sleep(3000);
				system("cls");
				Sleep(1000);
				do {
					player_list_response = player_screen->run();
					if (player_list_response != -1) {
						choose_member.insert(player_list_response);
					}
				} while (player_list_response != -1 && choose_member.size() != player_list.size());

				if (choose_member.size() != 0) {
					vector<NovicePlayer*> choose_player;
					for (set<int>::iterator it = choose_member.begin(); it != choose_member.end(); it++) {
						choose_player.push_back(player_list.at(*it));
					}
					int monster_num = (choose_player.size() * 0.7 >= 1) ? choose_player.size() * 0.7 : 1;
					vector<BaseMonster*> monster_list;
					for (int i = 0; i < monster_num; i++) {
						BaseMonster* goblin = new GoblinMonster;
						monster_list.push_back(goblin);
					}
					Battle* battle = new Battle(choose_player, monster_list, 0);
					system("cls");
					battle->run();
					if (battle->playerWin()) {
						goblin_monster_killed = true;
					}
					if (battle->monsterWin()) {
						cout << "   遊戲即將結束";
						Sleep(1500);
						game_end = true;
					}

					for (int i = 0; i < player_list.size(); i++) {
						if (player_list.at(i)->getHp() == 0) {
							delete player_list.at(i);
							player_list.erase(player_list.begin() + i);
							i = -1;
						}
					}
					for (int i = 0; i < monster_list.size(); i++) {
						delete monster_list.at(i);
					}
					delete battle;
				}
				delete player_screen;

				system("cls");
				current_field->display();
				if (current_field == First_floor) {
					cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
				}

				break;
			case 121:
				system("cls");
				Sleep(1000);
				setCursor(4, 2);
				cout << "你已經進入了";
				Sleep(2000);
				setCursor(4, 4);
				cout << "cpsoo先生畢生追尋的";
				Sleep(2000);
				setCursor(4, 6);
				cout << "時空隧道";
				Sleep(2000);
				setCursor(4, 8);
				cout << "請稍待他找尋你命中注定的地點將時空折疊";
				Sleep(2000);
				setCursor(4, 10);
				cout << "把你送到未知的那個地方...";
				Sleep(4000);
				int x, y;
				do {
					x = rand() % current_field->getMapSize().width;
					y = rand() % current_field->getMapSize().height;
				} while (current_field->getSymbol(x, y) != 0);
				current_field->setPosition(x, y);
				system("cls");
				Sleep(500);
				continue;
				break;
			case 131:
				if (!current_field->isStepped()) {
					system("cls");
					current_field->setGrid(current_field->getCurrentPosition(), "紙");
					current_field->display();
					++paper_amount;
					setCursor(2, 22);
					cout << "恭喜你撿到一張cpsoo先生失落已久的紙條!!";
					current_field->step();
					setCursor(2, 24);
					cout << "已撿回 " << paper_amount << " 張紙條";
				}
				break;
			}

			// 2F
			NotNotGame* notnotgame = nullptr;
			switch (current_symbol) {
			case 200:
				//Sleep(1000);
				system("cls");
				Sleep(500);
				setCursor(3, 3);
				cout << "電梯下樓...";
				Sleep(1000);
				current_field = First_floor;
				system("cls");
				Sleep(500);
				current_field->display();
				if (current_field == First_floor) {
					cout << "  已撿回 " << paper_amount << " 張紙條\n\n";
				}
				break;

			case 201:
				if (!second_floor_finish) {
					system("cls");
					End_2F End;
					End.run();
					system("cls");
					player_screen = new Menu;
					int player_list_response;
					player_screen->question_name = "查看您的隊伍成員";
					player_screen->instruction.push_back("請以↑↓鍵移動游標，並以Enter選擇參加戰鬥的隊員，選擇完畢請按下Esc；或直接按Esc鍵退出");
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->options.push_back(player_list.at(i)->getName());
					}
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
					}
					system("cls");
					do {
						player_list_response = player_screen->run();
						if (player_list_response != -1) {
							choose_member.insert(player_list_response);
						}
					} while (player_list_response != -1 && choose_member.size() != player_list.size());
					if (choose_member.size() != 0) {
						vector<NovicePlayer*> choose_player;
						for (set<int>::iterator it = choose_member.begin(); it != choose_member.end(); it++) {
							choose_player.push_back(player_list.at(*it));
						}
						int monster_num = (choose_player.size() * 0.7 >= 1) ? choose_player.size() * 0.7 : 1;
						vector<BaseMonster*> monster_list;
						for (int i = 0; i < monster_num; i++) {
							BaseMonster* zombie = new ZombieMonster;
							monster_list.push_back(zombie);
						}
						Battle* battle = new Battle(choose_player, monster_list, 0);
						system("cls");
						battle->run();
						if (battle->playerWin()) {
							zombie_monster_killed = true;
							second_floor_finish = true;
							system("cls");
							Sleep(500);
							cout << "\n\n   電梯上樓...";
							current_field = Third_floor;
							Sleep(1000);
							if (!third_floor_entered) {
								system("cls");
								Welcome_3F welcome;
								welcome.run();
								Sleep(500);
								third_floor_entered = true;
							}
							system("cls");
							current_field->display();
						}
						else if (battle->monsterWin()) {
							cout << "   遊戲即將結束";
							Sleep(1500);
							game_end = true;
							break;
						}
						else {
							current_field->setPosition(28, 27);
							current_field->display();
						}

						for (int i = 0; i < player_list.size(); i++) {
							if (player_list.at(i)->getHp() == 0) {
								delete player_list.at(i);
								player_list.erase(player_list.begin() + i);
								i = -1;
							}
						}
						for (int i = 0; i < monster_list.size(); i++) {
							delete monster_list.at(i);
						}
						delete battle;
					}
					delete player_screen;
				}
				else {
					system("cls");
					Sleep(500);
					cout << "\n\n   電梯上樓...";
					current_field = Third_floor;
					Sleep(500);
					system("cls");
					current_field->display();
				}
				break;
			case 233:
			case 235:
			case 239:
			case 243:
			case 247:
				cout << "  你猜錯方向了啦啦啦啦啦 所有成員將被扣５點經驗值";
				for (int i = 0; i < player_list.size(); i++) {
					player_list.at(i)->minusExp(5);
				}

				break;
			case 261:
				if (!first_notnot) {
					system("cls");
					setCursor(2, 1);
					cout << "歡迎！";
					Sleep(2000);
					setCursor(2, 3);
					cout << "為了迎接風塵僕僕的你到來";
					Sleep(2000);
					setCursor(2, 5);
					cout << "CAS先生早已精心為你設計了一場刺激的挑戰";
					Sleep(2000);
					setCursor(2, 7);
					cout << "通過考驗後即可繼續旅程，但若不幸挑戰失利您將被送回原位，重新參加挑戰";
					Sleep(2000);
					setCursor(2, 9);
					cout << "準備好了嗎！";
					Sleep(2000);
					setCursor(2, 11);
					cout << "以下是一些和方向相關的問題，請在時限內按下符合題意的按鍵，";
					Sleep(1500);
					setCursor(2, 13);
					cout << "您有一次答錯的機會，";
					Sleep(1500);
					setCursor(2, 15);
					cout << "別緊張放輕鬆，挑戰即將開始！";
					Sleep(2500);

					notnotgame = new NotNotGame(15);
					if (!notnotgame->run(player_list)) {
						current_field->setPosition(7, 26);
						delete notnotgame;
					}
					else {
						current_field->setPosition(9, 26);
						first_notnot = true;
						delete notnotgame;
					}
					current_field->display();
				}
				break;
			case 262:
				if (!second_notnot) {
					system("cls");
					setCursor(2, 1);
					cout << "遠道而來的你辛苦了！";
					Sleep(2000);
					setCursor(2, 3);
					cout << "看到你先前優異的表現";
					Sleep(2000);
					setCursor(2, 5);
					cout << "CAS先生決定再多給你一點考驗";
					Sleep(2000);
					setCursor(2, 7);
					cout << "這次的題數比剛剛稍微多了點";
					Sleep(2000);
					setCursor(2, 9);
					cout << "不過相信你必定可以跟剛剛一樣順利通過的!!";
					Sleep(2500);

					notnotgame = new NotNotGame(25);
					if (!notnotgame->run(player_list)) {
						current_field->setPosition(19, 26);
						delete notnotgame;
						continue;
					}
					else {
						current_field->setPosition(18, 27);
						second_notnot = true;
						delete notnotgame;
						continue;
					}
				}
				break;
			case 271:
				system("cls");
				Sleep(1000);
				setCursor(4, 2);
				cout << "樓下那位熱衷實(搞)驗(鬼)的cpsoo先生";
				Sleep(2000);
				setCursor(4, 4);
				cout << "不小心玩過頭將你所處的空間折了起來";
				Sleep(2000);
				setCursor(4, 6);
				cout << "將LSD廣場的另一端";
				Sleep(2000);
				setCursor(4, 8);
				cout << "與你腳下建起了時空走廊";
				Sleep(2000);
				setCursor(4, 10);
				cout << "稍待一會，空間即將切換...";
				Sleep(4000);
				int x, y;
				do {
					x = rand() % current_field->getMapSize().width;
					y = rand() % current_field->getMapSize().height;
				} while (current_field->getSymbol(x, y) != 0);
				current_field->setPosition(x, y);
				system("cls");
				Sleep(500);
				continue;
				break;
			}

			// 3F
			switch (current_symbol) {
			case 300:
				system("cls");
				Sleep(500);
				setCursor(3, 3);
				cout << "電梯下樓...";
				Sleep(1000);
				current_field = Second_floor;
				system("cls");
				Sleep(500);
				current_field->display();
				break;

			case 301:
				player_screen = new Menu;
				int player_list_response;
				player_screen->question_name = "查看您的隊伍成員";
				player_screen->instruction.push_back("請以↑↓鍵移動游標，並以Enter選擇參加戰鬥的隊員，選擇完畢請按下Esc；或直接按Esc鍵退出");
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->options.push_back(player_list.at(i)->getName());
				}
				for (int i = 0; i < player_list.size(); i++) {
					player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
				}
				system("cls");
				do {
					player_list_response = player_screen->run();
					if (player_list_response != -1) {
						choose_member.insert(player_list_response);
					}
				} while (player_list_response != -1 && choose_member.size() != player_list.size());

				if (choose_member.size() != 0) {
					vector<NovicePlayer*> choose_player;
					for (set<int>::iterator it = choose_member.begin(); it != choose_member.end(); it++) {
						choose_player.push_back(player_list.at(*it));
					}
					int monster_num = (choose_player.size() * 0.7 >= 1) ? choose_player.size() * 0.7 : 1;
					vector<BaseMonster*> monster_list;
					for (int i = 0; i < monster_num; i++) {
						BaseMonster* jwmonster = new JWMonster;
						monster_list.push_back(jwmonster);
					}
					Battle* battle = new Battle(choose_player, monster_list, 0);
					system("cls");
					battle->run();
					if (battle->playerWin()) {
						system("cls");
						EndScreen end_screen;
						game_end = true;
						break;
					}
					else if (battle->monsterWin()) {
						cout << "   遊戲即將結束";
						Sleep(1500);
						game_end = true;
						break;
					}
					else {
						current_field->display();
					}

					for (int i = 0; i < player_list.size(); i++) {
						if (player_list.at(i)->getHp() == 0) {
							delete player_list.at(i);
							player_list.erase(player_list.begin() + i);
							i = -1;
						}
					}
					for (int i = 0; i < monster_list.size(); i++) {
						delete monster_list.at(i);
					}
					delete battle;
				}
				delete player_screen;

				break;
			case 311:
				system("cls");
				current_field->setPosition(1, 3);
				current_field->display();
				current_field->setPosition(4, 2);
				current_field->display();
				current_field->setPosition(3, 8);
				current_field->display();
				current_field->setPosition(1, 6);
				current_field->display();
				current_field->setPosition(10, 7);
				current_field->display();
				break;
			case 312:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "樓下廣場的整修工程";
				Sleep(1500);
				setCursor(3, 3);
				cout << "不小心對天花板鑽破了個洞";
				Sleep(1500);
				setCursor(3, 5);
				cout << "位置";
				Sleep(1500);
				setCursor(3, 7);
				cout << "該好就在你的腳下";
				Sleep(1500);
				setCursor(3, 9);
				cout << "小心!!!";
				Sleep(1000);
				system("cls");
				current_field = Second_floor;
				current_field->setPosition(15, 20);
				current_field->display();
				break;
			case 313:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "台南連日的大雨";
				Sleep(1500);
				setCursor(3, 3);
				cout << "又大又急";
				Sleep(1500);
				setCursor(3, 5);
				cout << "淹了頂樓甚至";
				Sleep(1500);
				setCursor(3, 7);
				cout << "衝破了你頭上的屋頂";
				Sleep(1500);
				setCursor(3, 9);
				cout << "......";
				Sleep(1500);
				setCursor(3, 11);
				cout << "大水把你往後沖了好一段路";
				Sleep(1500);
				setCursor(3, 13);
				cout << "受了不少傷";
				Sleep(3000);
				setCursor(3, 16);
				cout << "所有人血量少了20點";
				Sleep(2500);
				system("cls");
				current_field->setPosition(2, 9);
				current_field->display();
				break;
			case 314:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "終於踏進這一格的您辛苦了";
				Sleep(1500);
				setCursor(3, 3);
				cout << "雖然這依然不是正確的密道";
				Sleep(1500);
				setCursor(3, 5);
				cout << "如果已經找很久的話偷偷提示您";
				Sleep(1500);
				setCursor(3, 7);
				cout << "別太早轉彎多走幾步路必是值得ㄉ";
				Sleep(1500);
				setCursor(3, 9);
				cout << "雖然你腳下的地板";
				Sleep(1500);
				setCursor(3, 11);
				cout << "早已裂開一個無法挽回的洞";
				Sleep(1500);
				setCursor(3, 13);
				cout << "請小心，摔落即將開始...";
				current_field = Second_floor;
				Sleep(2500);
				system("cls");
				current_field->setPosition(27, 13);
				current_field->display();
				break;
			case 315:
				system("cls");
				Sleep(500);
				setCursor(3, 1);
				cout << "今天的狀況異常的危急";
				Sleep(1500);
				setCursor(3, 3);
				cout << "就跟我們的每一次期末一樣";
				Sleep(1500);
				setCursor(3, 5);
				cout << "如果你還沒發現異狀請小心踏下未來每一步";
				Sleep(1500);
				setCursor(3, 7);
				cout << "如果已經發現了";
				Sleep(1500);
				setCursor(3, 9);
				cout << "恭喜你";
				Sleep(1500);
				setCursor(3, 11);
				cout << "這裡是少數尚未危機四伏的巷子";
				Sleep(1500);
				setCursor(3, 13);
				cout << "除了，風有點大，你要站不穩了...";
				Sleep(2500);
				system("cls");
				current_field->setPosition(1, 8);
				current_field->display();
				break;
			}
		}
		if (game_end) {
			break;
		}
		// Let user press a key
		{
			do {
				press = _getch();
				if (press == 224) {
					press = _getch();
				}
				switch (press) {
				case 75:
				case 'A':
					press = 'a';
					break;
				case 77:
				case 'D':
					press = 'd';
					break;
				case 72:
				case 'W':
					press = 'w';
					break;
				case 80:
				case 'S':
					press = 's';
					break;
				case 'm':
					serialize();
					break;
				case 'p':
					player_screen = new Menu;
					int player_list_response;
					player_screen->question_name = "查看您的隊伍成員";
					player_screen->instruction.push_back("請以↑↓鍵移動游標，並以Esc鍵退出");
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->options.push_back(player_list.at(i)->getName());
					}
					for (int i = 0; i < player_list.size(); i++) {
						player_screen->option_descriptions.push_back(player_list.at(i)->showInfo());
					}
					system("cls");
					player_list_response = player_screen->run();
					while (player_list_response != -1) {
						player_list_response = player_screen->run();
					}
					delete player_screen;
					system("cls");
					current_field->display();
					break;
				case 'b':
					system("cls");
					backpack.display();
					system("cls");
					current_field->display();
					break;
				case 'v':
					system("cls");
					if (current_field == First_floor) {
						legend_1F legend;
						legend.display();
					}
					else if (current_field == Second_floor) {
						legend_2F legend;
						legend.display();
					}
					else if (current_field == Third_floor) {
						legend_3F legend;
						legend.display();
					}
					system("cls");
					current_field->display();
					break;
				}
			} while (!current_field->move(press) && press != 27);
		}

		if (press == 27) {
			break;
		}
		//	hot key in field screen end

		// moving
		++step_count;

		// detect current_symbol after moving
		current_symbol = current_field->getSymbol();

		int temp_level_sigma = 0;
		for (int i = 0; i < player_list.size(); i++) {
			temp_level_sigma += player_list.at(i)->getLevel();
		}
		if (temp_level_sigma > all_player_level_sigma) {
			for (int i = 0; i < temp_level_sigma - all_player_level_sigma; i++) {
				backpack.addWeightLimit();
			}
		}

		all_player_level_sigma = temp_level_sigma;

	}
	return game_end;
}

void Game::serialize()
{
	fstream file("record.txt", ios::out);

	// players
	for (int i = 0; i < player_list.size(); i++) {
		file << player_list.at(i)->serialize() << endl;
	}

	// backpack
	file << backpack.serialize() << endl;

	// current_field
	if (current_field == First_floor) {
		file << "@current_field$First_floor$#" << endl;
	}
	else if (current_field == Second_floor) {
		file << "@current_field$Second_floor$#" << endl;
	}
	else if (current_field == Third_floor) {
		file << "@current_field$Third_floor$#" << endl;
	}

	// positions in each field
	stringstream s1, s2;
	s1 << First_floor->getCurrentPosition().x;
	s2 << First_floor->getCurrentPosition().y;
	file << ("@First_floor$" + s1.str() + '$' + s2.str() + '$' + '#') << endl;
	s1.str(""); s1.clear(); s2.str(""); s2.clear();

	s1 << Second_floor->getCurrentPosition().x;
	s2 << Second_floor->getCurrentPosition().y;
	file << ("@Second_floor$" + s1.str() + '$' + s2.str() + '$' + '#') << endl;
	s1.str(""); s1.clear(); s2.str(""); s2.clear();

	s1 << Third_floor->getCurrentPosition().x;
	s2 << Third_floor->getCurrentPosition().y;
	file << ("@Third_floor$" + s1.str() + '$' + s2.str() + '$' + '#') << endl;
	s1.str(""); s1.clear(); s2.str(""); s2.clear();

	file << "@Game$ " << endl;
	file << paper_amount << ' ' << all_player_level_sigma << ' ' << second_floor_entered << ' ' << third_floor_entered << ' '
		<< second_floor_finish << ' ' << first_notnot << ' ' << second_notnot << ' '
		<< goblin_monster_killed << ' ' << zombie_monster_killed << endl;

	file << "#end#";
	file.close();

}

void Game::unserialize()
{
	// destructor

	fstream file("record.txt", ios::in);

	string input;
	string label;
	stringstream ss;
	while (1) {
		getline(file, input);
		if (input.length() == 0) {
			break;
		}
		int begin, end;
		begin = input.find('@');
		end = input.find('$');
		if (begin == -1 || end == -1) {
			break;
		}
		label = string(input, begin + 1, end - begin - 1);
		if (label == "Game") {
			break;
		}
		if (label == "NovicePlayer") {
			player_list.push_back(NovicePlayer::unserialize(input));
		}
		else if (label == "OrcPlayer") {
			player_list.push_back(OrcPlayer::unserialize(input));
		}
		else if (label == "KnightPlayer") {
			player_list.push_back(KnightPlayer::unserialize(input));
		}
		else if (label == "MagicianPlayer") {
			player_list.push_back(MagicianPlayer::unserialize(input));
		}
		else if (label == "Backpack") {
			backpack.unserialize(input);
		}
		else if (input == "@current_field$First_floor$#") {
			current_field = First_floor;
		}
		else if (input == "@current_field$Second_floor$#") {
			current_field = Second_floor;
		}
		else if (input == "@current_field$Third_floor$#") {
			current_field = Third_floor;
		}
		else if (label == "First_floor") {
			int x, y;
			int begin_posi, end_posi;
			begin_posi = input.find('$');
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> x; ss.str(""); ss.clear();

			begin_posi = end_posi;
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> y; ss.str(""); ss.clear();

			First_floor->setPosition(x, y);
		}
		else if (label == "Second_floor") {
			int x, y;
			int begin_posi, end_posi;
			begin_posi = input.find('$');
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> x; ss.str(""); ss.clear();

			begin_posi = end_posi;
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> y; ss.str(""); ss.clear();

			Second_floor->setPosition(x, y);
		}
		else if (label == "Third_floor") {
			int x, y;
			int begin_posi, end_posi;
			begin_posi = input.find('$');
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> x; ss.str(""); ss.clear();

			begin_posi = end_posi;
			end_posi = input.find('$', begin_posi + 1);
			ss << string(input, begin_posi + 1, end_posi - begin_posi - 1);
			ss >> y; ss.str(""); ss.clear();

			Third_floor->setPosition(x, y);
		}
	}

	file >> paper_amount >> all_player_level_sigma >> second_floor_entered >> third_floor_entered
		>> second_floor_finish >> first_notnot >> second_notnot
		>> goblin_monster_killed >> zombie_monster_killed;

}

Game::Game()
{
	srand(time(NULL));

	backpack.setPlayerList(&player_list);

	// Main_Menu //
	{
		Main_Menu.question_name = "遊戲主選單";

		Main_Menu.instruction.push_back("歡迎進入我的RPG！");
		Main_Menu.instruction.push_back("這是一款精心製作的遊戲");
		Main_Menu.instruction.push_back("帶您體驗小大一苦中作樂的新鮮大學生活");
		Main_Menu.instruction.push_back("");
		Main_Menu.instruction.push_back("請以鍵盤↑↓鍵移動綠色游標，並以 Enter 選擇功能");
		Main_Menu.instruction.push_back("");
		Main_Menu.instruction.push_back("準備好了嗎？那就讓我們開始吧~~");

		Main_Menu.options.push_back("進入遊戲");
		Main_Menu.options.push_back("載入存檔");
		Main_Menu.options.push_back("退　　出");

		Main_Menu.option_descriptions.push_back("讓我們邁步踏入未知的世界迎接挑戰吧");
		Main_Menu.option_descriptions.push_back("從過去的紀錄再次出發");
		Main_Menu.option_descriptions.push_back("該繼續準備期末囉:D");
	}

	store = new Store(&backpack, &money);
}

Game::~Game()
{
	// delete player series objects //
	for (int i = 0; i < player_list.size(); i++) {
		delete player_list.at(i);
	}

	delete store;

	delete First_floor;
	delete Second_floor;
	delete Third_floor;
}

void Game::run()
{
	int main_menu_chosen;
	bool close = false;
	while (!close) {	// main menu begin
		system("cls");
		main_menu_chosen = Main_Menu.run();

		// options of main menu //
		switch (main_menu_chosen) {
		case 0:	// main_menu_chosen == 0 begin
			system("cls");

			if (reset) {
				if (player_list.size() > 0) {
					for (int i = 0; i < player_list.size(); i++) {
						delete player_list.at(i);
					}
					player_list.clear();
				}

				generatePlayers();

				initializeFirstFloor();
				initializeSecondFloor();
				initializeThirdFloor();

				current_field = First_floor;

				backpack.clear();

				money = 0;
				paper_amount = 0;
				all_player_level_sigma = 0;

				second_floor_entered = false;
				third_floor_entered = false;

				second_floor_finish = false;

				first_notnot = false;
				second_notnot = false;

				goblin_monster_killed = false;
				zombie_monster_killed = false;

				Welcome_1F welcome;
				system("cls");
				welcome.run();
				system("cls");
			}

			reset = play();

			break;	// main_menu_chosen == 0 end

		case 1:
			initializeFirstFloor();
			initializeSecondFloor();
			initializeThirdFloor();
			unserialize();
			reset = play();

			break;
		case 2:
			close = true;
		}

	}	// main menu end

}
