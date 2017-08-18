///////////////////////////////////////////////
/* いきなりメイン関数から作る                */
/* メイン関数でおこなう処理を記述する        */
/* maze20161010.c                            */
/*                                           */
///////////////////////////////////////////////


#include<stdio.h>
#include<windows.h> // Windows特有のヘッダーライブラリ


/* 迷路のデータ構造を作る */
#define MAX_TATE 11
#define MAX_YOKO 11

/* 方角 */
#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

/* 迷路を構成するブロックの種類 */
#define KABE -1
#define TURO 0
#define START -2
#define GOAL -10

//構造体：ロボットから出力が複数あるため
//構造体としてまとめて出力させる方法を採用
struct robot_output{
	int x;
	int y;
	int muki;
	int mae;
	int ushiro;
	int migi;
	int hidari;
};

//int temp;

/* ロボットからの出力が複数あるため */
/* 構造体としてまとめて出力させる方法を取る */

struct robot_output robot(
//int robot(
	int x,	//robotのx座標
	int y,	//robotのy座標
	int muki,//robotの向き
	int data[MAX_TATE][MAX_YOKO]	//robot周辺の迷路情報
);

int main(int arg, char *argv[])
{
/* ループ用変数 */
int i, j, k;

/* 時刻用変数 */
int time;
/* ロボットの座標と向きを入れるための変数 */
int x;
int y;
int muki;

/* ロボットのある時刻における出力（戻り値）を入れるための変数 */
struct robot_output temp;

/* 時刻を進ませるためのキーボード入力用変数 */
int enter;

/* 迷路のデータ構造を作る */
/* 2次元配列を使う。通路は０、壁は－1で表される。 */
int data[MAX_TATE][MAX_YOKO]=
//0		1		2		3		4		5		6		7		8		9		10
{
-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	//0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	-1	,	//1
-1	,	-1	,	-1	,	0	,	-1	,	-1	,	-1	,	-1	,	-1	,	0	,	-1	,	//2
-1	,	0	,	0	,	0	,	-1	,	0	,	0	,	0	,	-1	,	0	,	-1	,	//3
-1	,	0	,	-1	,	-1	,	-1	,	0	,	-1	,	0	,	-1	,	-1	,	-1	,	//4
-1	,	0	,	-1	,	0	,	0	,	0	,	-1	,	0	,	0	,	0	,	-1	,	//5
-1	,	0	,	-1	,	0	,	-1	,	-1	,	-1	,	-1	,	-1	,	0	,	-1	,	//6
-1	,	0	,	0	,	0	,	-1	,	0	,	0	,	0	,	-1	,	0	,	-1	,	//7
-1	,	0	,	-1	,	-1	,	-1	,	0	,	-1	,	-1	,	-1	,	0	,	-1	,	//8
-1	,	0	,	0	,	0	,	0	,	0	,	-1	,	0	,	0	,	0	,	0	,	//9
-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	,	-1	};//10

/* スタートとゴールの配列要素にそれぞれに対応した数値を代入 */
data[1][0] = START;
data[9][10]= GOAL;

/* 迷路を表示する */
for(i=0; i < MAX_TATE; i++){
	for(j=0; j < MAX_YOKO; j++)
		switch(data[i][j]){
			case KABE:
				printf("■");
				break;
			case TURO:
				printf("　");
				break;
			case START:
				printf("ス");
				break;
			case GOAL:
				printf("ゴ");
				break;
		}
	printf("\n");
}
printf("\n");

/* ロボットの座標と向きを初期化 */
   x=1;
   y=1;
muki=EAST;
data[y][x]=1;

   /* 迷路を解くロボットアルゴリズムの記述 */

/* while文を用いて1ステップずつ時間更新 */
while(1){
   /* ロボットは1ステップにつき、1動作実行する */
   temp = robot(x,y,muki,data);
   x = temp.x;
   y = temp.y;
   muki = temp.muki;

   /* 迷路と経路を表示する */
	for(i=0; i < MAX_TATE; i++){
		for(j=0; j < MAX_YOKO; j++)
			/* robot関数で記録しておいた通った座標の通過回数を表示する仕組み */
			if(data[i][j] > 0){
				printf("%2d",data[i][j]);
			}else{
			switch(data[i][j]){
				case KABE:
					printf("■");
					break;
				case TURO:
					printf("　");
					break;
				case START:
					printf("ス");
					break;
				case GOAL:
					printf("ゴ");
					break;
			}
			}
		printf("\n");
	}
	/* 迷路の2次元配列にロボットのたどった経路のデータを上書きして表示 */
	/* 次のステップに進む */
	printf("Time is %4d. Next Time: Hit 「1 Key」!",time);
//	scanf("%d",&enter);
//	if(enter != 1) break;



    Sleep(100); // 自動化(数字が小さいほど早く動作する)




	time = time + 1;
}

   return(0);
}

////////////////////////////////////////////////////////////////////////
/* 関数robot                                                          */
/* 入力として、迷路データと現時刻のロボットの座標と向きを             */
/* 与えられると、センサー情報を使って次の座標に移動するか、           */
/* 一定の角度だけ回転した後移動するロボットを実現する。               */
/* 出力として、動作後のロボットの座標と向き、前後左右の壁の状況を返す */
////////////////////////////////////////////////////////////////////////
struct robot_output robot( //多出力バージョン
//int robot(
	int x,
	int y,
	int muki,
	int data[MAX_TATE][MAX_YOKO]
)
{
/* ロボットの前後左右のセンサー情報のための変数 */
int mae, ushiro, migi, hidari;
struct robot_output output;
/* ロボットの次の時刻の位置や向き、センサー情報を入れておく           */
/* ための変数で、最後にロボットはこの変数に入っているデータを出力する */

/* 現時刻の座標と向きからロボット周囲のセンサー情報を取得する */
switch(muki){
	case EAST:
		mae   = data[y][x+1];
		ushiro= data[y][x-1];
		migi  = data[y+1][x];
		hidari= data[y-1][x];
		break;
	case SOUTH:
		mae   = data[y+1][x];
		ushiro= data[y-1][x];
		migi  = data[y][x-1];
		hidari= data[y][x+1];
		break;
	case WEST:
		mae   = data[y][x-1];
		ushiro= data[y][x+1];
		migi  = data[y-1][x];
		hidari= data[y+1][x];
		break;
	case NORTH:
		mae   = data[y-1][x];
		ushiro= data[y+1][x];
		migi  = data[y][x+1];
		hidari= data[y][x-1];
		break;
}
/* ロボットの前後左右の状況を表示する */
printf("前=%2d 後=%2d 右=%2d 左=%2d 向き=%2d \n",mae, ushiro, migi, hidari, muki);

/* 周囲の状況により動作を決定する */

//場合分けが多いのでケース文を使うことにする・・・とは書いたもののまずはif文で作る

if(mae != -10){ //-10はゴール地点を表す

   //ここから右手法

   if(migi != -1){

        //①90度右回転


        muki = muki+1;
        muki = muki%4;


        //②前進



   switch(muki){
        case EAST:
             x = x + 1;
             break;
        case SOUTH:
             y = y + 1;
             break;
        case WEST:
             x = x - 1;
             break;
        case NORTH:
             y = y - 1;
             break;
             }



   }else{



        if(mae != -1){



             //①前進



        switch(muki){
        case EAST:
             x = x + 1;
             break;
        case SOUTH:
             y = y + 1;
             break;
        case WEST:
             x = x - 1;
             break;
        case NORTH:
             y = y - 1;
             break;
             }



        }else{



             if(hidari != -1){

                  //①270度右回転


                  muki = muki + 3;
                  muki = muki % 4;


                  //②前進



             switch(muki){
        case EAST:
             x = x + 1;
             break;
        case SOUTH:
             y = y + 1;
             break;
        case WEST:
             x = x - 1;
             break;
        case NORTH:
             y = y - 1;
             break;
             }



             }else{



             //①180度右回転


             muki = muki + 2;
             muki = muki % 4;


             //②前進



             switch(muki){
        case EAST:
             x = x + 1;
             break;
        case SOUTH:
             y = y + 1;
             break;
        case WEST:
             x = x - 1;
             break;
        case NORTH:
             y = y - 1;
             break;
             }



           }
        }
    }



    //ここまで右手法


}else{
      // ゴールに到着したのでもう動かない
}


//90度右回転用のプログラム
 //muki = muki+1;
 //muki = muki%4;


//180度右回転用のプログラム
 //muki = muki + 2;
 //muki = muki % 4;


//90度左回転用 = 270度右回転用のプログラム
 //muki = muki + 3;
 //muki = muki % 4;

/* 更新後の座標を通過したことを表すため回数をカウント */
data[y][x]=data[y][x]+1;



// 前進用のプログラム

/*     switch(muki){
             case EAST:
                x = x + 1;
                break;
             case SOUTH:
                y = y + 1;
                break;
             case WEST:
                x = x - 1;
                break;
             case NORTH:
                y = y - 1;
                break;
                }                    */

/* メイン関数にロボットの動作後の座標、向き、前後左右の壁の状況を変数outputで返す */
output.x = x;
output.y = y;
output.muki = muki;
output.mae = mae;
output.ushiro = ushiro;
output.migi = migi;
output.hidari = hidari;
return output;
}
