#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>

using namespace std;

const int height=10, width=15;

void panel_flash(){
  system("cls"); //clear console each time

  random_device rd; //random device creation and generation using random lib
  mt19937 md(rd());
  uniform_int_distribution<int> panel_dist(0,1); //0 and 1 to translate to bool

  vector<vector<char>> panel_2d; //2d vector creation and filling with chars
  for(int i = 0;i<height;i++){
    vector<char> panel_1d(0);
    for(int j = 0;j<width;j++){
      bool on_off = panel_dist(md);
      if(on_off) {
        panel_1d.push_back('1');
      } else {
        panel_1d.push_back('0');
      }
    }
    panel_2d.push_back(panel_1d);
    panel_1d.clear();
  }

  for(auto &x:panel_2d){
    for(auto y:x){
      cout << y << ' ';
    }
    cout << endl;
  }
  Sleep(100);
}

int main() {
  bool start = true;
  while(start){
    panel_flash();
    if(GetAsyncKeyState(VK_RETURN)){
      start = false;
    }
  }

  return 0;
}
