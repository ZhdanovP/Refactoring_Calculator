#include "tic_tac_toe.hpp"

#include <iostream> 
#include <cstring> 
#include <clocale>
using namespace std;

char win = '-'; 
char PlayerName1[80], PlayerName2[80];
char cells[9] = { '-','-','-','-','-','-','-','-','-' };

void show_cells() {
    system("cls");

    cout << "Числа клеток: \n";
    cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

    cout << "Текущая ситуация (---пустой):\n" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

}

Move ask_move(int num, std::istream& is) {
  Move move;

  if (num == 1) {
    cout << PlayerName1;
    move.value = 'X';
  }
  else {
    cout << PlayerName2;
    move.value = 'O';
  }

  int cell;
  cout << ",введите номер ячейки,сделайте свой ход:";
  is >> cell;

  while (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
    cout << "Введите номер правильного ( 1-9 ) или пустой ( --- ) клетки , чтобы сделать ход:";
    is >> cell;
    cout << "\n";
  }

  move.cell = cell -1;
  return move;
}

void make_move(const Move& move) {
    cells[move.cell] = move.value;
}

char check()
{
    for (int i = 0; i < 3; i++) 
        if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2])
            return cells[i]; 
        else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) 
            return cells[i];
        else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]))
            return cells[i]; 
    return '-'; 
}

void result() {
    if (win == 'X')
        cout << PlayerName1 << "вы  выиграли поздравляем " << PlayerName2 << " а вы проиграли..." << endl;
    else if (win == 'O') cout << PlayerName2 << "вы  выиграли поздравляем  " << PlayerName1 << " а вы проиграли..." << endl;

}

void run(std::istream& is) {
    setlocale(LC_ALL, "Russian");
    do {
        cout << "Введите имя первого игрока : ";
        is >> PlayerName1;

        cout << "Введите имя второго игрока: ";
        is >> PlayerName2;
        cout << "\n";
    } while (!strcmp(PlayerName1, PlayerName2));
    
    show_cells();

    for (int move = 1; move <= 9; move++) {
        Move move_data;
        if (move % 2) {
          move_data = ask_move(1, is);
        }
        else {
          move_data = ask_move(2, is);
        } 
        
        make_move(move_data);
        show_cells();
        
        if (move >= 5)
        {
            win = check();
            if (win != '-')
                break;
        }
  
    }

    result();
}
