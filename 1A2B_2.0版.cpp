#include<bits/stdc++.h>
//#include<conio.h>
using namespace std;

bool check_duplicate(vector<int> v){
     /*
     接收vector<int> 型態別的變數

     檢測v陣列中有無重複數值

     無重複回傳TRUE
     */
     int flag[10]={0};
     for(int i=0;i<v.size();++i){
          flag[v[i]]+=1;
          if(flag[v[i]]>1)return 0;
     }
     return 1;
}

bool check_length(string s, int length){
     /*
     接收vector<int> 型態別的變數
     和int型態別的變數代表需求長度

     檢測v陣列長度是否符合需求長度

     長度正確回傳TRUE
     */
     return s.size()==length;
}

bool check_number(string s){
     /*
     接收vector<int> 型態別的變數

     檢測v陣列是否參雜字元

     無參雜字元回傳TRUE
     */
     for(char e:s){
          if(!isdigit(e))return 0;
     }
     return 1;
}

vector<int> input(int length, bool hide=0){
     /*
     接收int型態別的變數代表需求長度
     處理輸入數列的部分
     
     hide接收bool型態別變，為隱藏功能，輸入的數列將影藏顯示

     回傳值型態別為vector<int>
     保證回傳陣列符合需求長度且無重複數值
     */
     vector<int> v(length);
     string num;
     while(true){
          if(hide){
				cout<<"No!!!\n";
               /*
               注意:此功能目前無法在google colab上執行
               
               int idx=0;
               while(idx<length){
                    char ch=getch();
                    if(isdigit(ch)){
                         v[idx++] = ch-'0';
                         putchar('*');
                    }
               }
               putchar('\n');*/
          }else{
               cin>>num;
               if(num=="yeet"){
                    while(true)cout<<"翻桌啦，不玩了\n";//彩蛋
               }else if(!check_number(num)){
                    cout<<"The input number must be 0~9\n";
                    continue;
               }else if(!check_length(num, length)){
                    cout<<"Wrong input length\n";
                    continue;
               }else{
                    for(int i=0;i<num.size();++i){
                         v[i] = num[i]-'0';
                    }
               }
          }
          
          if(!check_duplicate(v)){
               cout<<"Duplicate numbers are not allowed\n";
          }else{
               break;
          }
     }
     return v;
}

vector<int> set_number(int length, bool user_create=0){
     /*
     接收int型態別的變數代表需求長度
     和bool型態別的變數代表是否需要隨機生成數列

     處理生成答案數列的部分
     
     回傳值型態別為vector<int>
     保證回傳陣列符合需求長度且無重複數值
     */
     int flag[10]={0,1,2,3,4,5,6,7,8,9};
     vector<int> v(length);
     if(user_create){
          cout<<"Please input your answer: ";
          return input(length);//隱藏模式開關input(length, 1);
     }
     for(int i=0;i<10;++i)
          swap(flag[i],flag[rand()%10]);
     for(int i=0;i<length;++i)
          v[i]=flag[i];
     return v;
}

pair<int, int> deter(vector<int> ans, vector<int> input)
{
     /*
     接收vector<int>型態別的變數代表答案
     和接收vector<int>型態別的變數代表輸入數列

     處理答案和生成數列比對，並輸出幾A幾B
     
     回傳值型態別為bool代表是否猜對
     */
     int n=ans.size();
     int A=0,B=0;
     for(int i=0;i<n;i++)
     {
          if(ans[i]==input[i])
          {
               A++;
          }
          else
          {
               for(int count=0;count<n;count++)
               {
                    if(input[i]==ans[count])
                    {
                         B++;
                         break;
                    }
               }
          }
     }
     
     return make_pair(A,B);
}

void report(vector<int> ans, vector<vector<int>> record, long long time, int play_times, string name){
     /*
     戰報模板，接收所有需求的參數

     輸出戰報
     
     無回傳
     */
     int min=time/60, sec=time%60, length=ans.size();
     cout<<name<<" result report\n";
     for(int i=0;i<23;++i)cout<<"-\n"[i==22];
     cout<<"The number  |\nyou guessed"<<" | "<<"result"<<'\n';
     for(int i=0;i<23;++i)cout<<"-\n"[i==22];
     for(auto num:record){
          for(int i=0;i<11-length;++i)cout<<' ';
          for(int e:num)cout<<e;
          cout<<" | ";
          auto result = deter(ans, num);
          cout<<result.first<<"A"<<result.second<<"B";
          cout<<'\n';
     }
     cout<<"總遊戲時間: "<<min<<'m'<<sec<<'s'<<'\n';
     cout<<"總遊玩次數: "<<play_times<<'\n';
}

void props(vector<int> ans, int mode){
     /*
     接收vector<int>型態別的變數代表答案
     接收int型態別變數代表提示模式

     處理道具系統提示輸出
     
     無回傳
     */
      int length=ans.size();
      int idx = rand()%length;
      if(mode==1){
          cout<<"提示: "<<"答案中有數字"<<ans[idx]<<'\n';
      }else{
          cout<<"提示: "<<"答案為";
          for(int i=0;i<length;++i){
               if(i==idx)cout<<ans[idx];
               else cout<<'_';
          }
          cout<<'\n';
      }
}

void difficult(vector<int> &a, int mode)
{
     /*
     接收vector<int>型態別的變數代表答案
     接收int型態別變數代表更改模式

     mode 1為隨機交換答案數列中任兩位的數字，不保證一定會交換
     mode 2為隨機交換答案數列中某一位的數字，不保證一定會更換
     
     無回傳
     */
     int length = a.size();
     if(mode==1){
          
          swap(a[rand()%length],a[rand()%length]);
     }else if(mode==2){
          while(true)
          {
               a[rand()%length]=rand()%10;
               if(check_duplicate(a)==1)
               {
                    break;
               }
          }
     }
}

int random_skill(){
     /*
     無接收參數

     計算隨機技能機率用
     
     印出所選中的技能，並回傳該技能代表的數字
     技能 0，屏蔽對手的B格
     技能 1，屏蔽對手的A格
     技能 2，對手下回合無法使用技能

     */
     int num = rand()%10;
     switch(num){
          case 0:
          case 1:
               cout<<"Block the opponent's B\n";
               return 0;
          case 2:
          case 3:
               cout<<"Block the opponent's A\n";
               return 1;
          case 4:
          case 5:
               cout<<"Opponent cannot use skills next round\n";
               return 2;
          default:
               cout<<"You didn't get any skills\n";
               return -1;
     }
}

void single_mode(){
     //單人遊戲模式主函式

     /*
     ans:答案陣列
     tmp:暫存輸入陣列
     record:紀錄歷次陣列
     length:陣列長度
     play_times:記錄遊玩次數
     */
     vector<int> ans, tmp;
     vector<vector<int>> record;
     int length, play_times=0;   
     //選擇長度
     do{
          cout<<"set length(1~10): ";
          cin>>length;
     }while(0>=length||length>10);
     
     //選擇是否隨機生成答案
     cout<<"Do you want to randomly generate numbers?(Yes or No) ";
     string create;
     while(true){
          cin>>create;
          if(create=="Yes"){
               ans = set_number(length);
               break;
          }else if(create=="No"){
               ans = set_number(length, 1);
               break;
          }else{
               cout<<"Please input Yes or No\n";
          }
     }

     //選擇是否使用道具
     cout<<"Will you use the prop system?(Yes or No) ";
     int use_prop=0;
     while(true){
          cin>>create;
          if(create=="Yes"){
               use_prop=2;
               break;
          }else if(create=="No"){
               use_prop=0;
               break;
          }else{
               cout<<"Please input Yes or No\n";
          }
     }

     //選擇難易度
     cout<<"What degree of difficulty you want choose?(easy, normal, hard) ";
     int difficulty=-1;
     while(true){
          cin>>create;
          if(create=="easy"){
               difficulty=0;
               break;
          }else if(create=="normal"){
               difficulty=1;
               break;
          }else if(create=="hard"){
               difficulty=2;
               break;
          }else{
               cout<<"Please input easy or normal or hard\n";
          }
     }

     //遊戲過程
     //system("cls");此行程式無法在colab上使用
     int t=300;
     while(t--)cout<<'\b';//替代方案
     cout<<"Game Start\n";
     //紀錄時間
     time_t t_start, t_end;
     time(&t_start);
     while(true){
          play_times++;

          if(use_prop){
               int condition;
               cout<<"Do you want use props?(0 or 1): ";
               cin>>condition;
               if(condition){
                    use_prop--;
                    props(ans,use_prop);
               }
          }

          if(difficulty==1){
               if(play_times%5==0){
                    difficult(ans, 1);
                    cout<<"The order of answers has been changed\n";
               }
          }else if(difficulty==2){
               if(play_times%10==0){
                    difficult(ans,2);
                    cout<<"Answer numbers have been changed\n";
               }else if(play_times%5==0){
                    difficult(ans,1);
                    cout<<"The order of answers has been changed\n";
               }
          }

          cout<<"Please input number: ";
          tmp = input(length);
          record.emplace_back(tmp);
          cout<<setw(19)<<"result"<<": ";
          auto result = deter(ans, tmp);
          cout<<result.first<<"A"<<result.second<<"B\n";
          if(result.first==length){
               break;
          }

     }
     time(&t_end);

     cout<<"You win!!!!\n";
     report(ans, record, t_end-t_start, play_times, "your");
     
}

void competition_mode()
{
     //競技模式主程式

     /*
     ans1:玩家一答案陣列
     ans2:玩家二答案陣列
     input1, input2:暫存輸入陣列
     p1_record, p2_record:紀錄歷次陣列
     length:陣列長度
     p1_times, p2_times:記錄遊玩次數
     p1_state, p2_state:記錄玩家技能狀態(抽卡機功能)
     */
     vector<int> ans1, ans2;
     vector<int> input1,input2;
     vector<vector<int>> p1_record, p2_record;
     int p1_times=0, p2_times=0,p1_state=-1,p2_state=-1;
     int length;

     //選擇長度
     do{
          cout<<"Please choose 4-10 numbers"<<endl;
          cin>>length;
     }while(0>=length||length>10);
     
     //選擇模式
     int mode;
     cout<<"If you want to select the number ramdomly input 0"<<endl;
     cout<<"If you want to select the number by yourself input 1"<<endl;
     cout<<"If you want to leave input -1"<<endl;
     cin>>mode;
     if(mode==0)
     {
          ans1=set_number(length);
          ans2=set_number(length);

     }
     else if(mode==1)
     {
          ans1=set_number(length, 1);
          ans2=set_number(length, 1);
     }
     else
     {
          cout<<"Bye"<<endl;
          return;
     }

	//選擇是否使用抽卡機
     string create;
	 bool use_skill=0;
     cout<<"Will you use the skill system?(Yes or No) ";
     while(true){
          cin>>create;
          if(create=="Yes"){
               use_skill=1;
               break;
          }else if(create=="No"){
               use_skill=0;
               break;
          }else{
               cout<<"Please input Yes or No\n";
          }
     }
     //紀錄時間用
     time_t t_start, t_end;
     time(&t_start);
     //清除輸出
     int t=300;
     while(t--)cout<<'\b';//替代方案
     //遊戲過程
     while(true)
     {
          //玩家一部分
          cout<<"\nPlayer1\'s turn: "<<endl;
          //抽取技能
          if(p1_state!=2&&use_skill){
               cout<<"The skill player1 get: ";
               p2_state = random_skill();
          }
          //輸入數字
          cout<<"Please input number: ";
          input1=input(length);
          p1_record.push_back(input1);
          p1_times++;
          pair<int,int> result = deter(ans1, input1);
          cout<<setw(19)<<"result"<<": ";
          //印出結果
          if(p1_state==0){
               cout<<result.first<<"A"<<'?'<<"B\n";
               p1_state=-1;
          }else if(p1_state==1){
               cout<<'?'<<"A"<<result.second<<"B\n";
               p1_state=-1;
          }else{
               cout<<result.first<<"A"<<result.second<<"B\n";
          }
          if(result.first==length){
               cout<<"You are the winner"<<endl;
               break;
          }
          p1_state=-1;

          //玩家二部分
          cout<<"\nPlayer2\'s turn"<<endl;
          //抽取技能
          if(p2_state!=2&&use_skill){
               cout<<"The skill player2 get: ";
               p1_state = random_skill();
          }
          //輸入數字
          cout<<"Please input number: ";
          input2=input(length);
          p2_record.push_back(input2);
          p2_times++;
          result = deter(ans2, input2);
          cout<<setw(19)<<"result"<<": ";
          //印出結果
          if(p2_state==0){
               cout<<result.first<<"A"<<'?'<<"B\n";
               p2_state=-1;
          }else if(p2_state==1){
               cout<<'?'<<"A"<<result.second<<"B\n";
               p2_state=-1;
          }else{
               cout<<result.first<<"A"<<result.second<<"B\n";
          }
          if(result.first==length){
               cout<<"You are the winner"<<endl;
               break;
          }
          p2_state=-1;

     }
     time(&t_end);

     report(ans1, p1_record, t_end-t_start, p1_times, "player1's");
     report(ans2, p2_record, t_end-t_start, p2_times, "player2's");

     return ;
}

int main(){
     srand(time(NULL));
     
     //選擇遊玩模式
     string create;
      while(true){
          cout<<"What mode you want to choose?(single or competition)";
          cin>>create;
          if(create=="single"){
               single_mode();
               break;
          }else if(create=="competition"){
               competition_mode();
               break;
          }else{
               cout<<"Please input Yes or No\n";
          }
     }
     return 0;
}