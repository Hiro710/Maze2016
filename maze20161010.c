///////////////////////////////////////////////
/* �����Ȃ胁�C���֐�������                */
/* ���C���֐��ł����Ȃ��������L�q����        */
/* maze20161010.c                            */
/*                                           */
///////////////////////////////////////////////


#include<stdio.h>
#include<windows.h> // Windows���L�̃w�b�_�[���C�u����


/* ���H�̃f�[�^�\������� */
#define MAX_TATE 11
#define MAX_YOKO 11

/* ���p */
#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

/* ���H���\������u���b�N�̎�� */
#define KABE -1
#define TURO 0
#define START -2
#define GOAL -10

//�\���́F���{�b�g����o�͂��������邽��
//�\���̂Ƃ��Ă܂Ƃ߂ďo�͂�������@���̗p
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

/* ���{�b�g����̏o�͂��������邽�� */
/* �\���̂Ƃ��Ă܂Ƃ߂ďo�͂�������@����� */

struct robot_output robot(
//int robot(
	int x,	//robot��x���W
	int y,	//robot��y���W
	int muki,//robot�̌���
	int data[MAX_TATE][MAX_YOKO]	//robot���ӂ̖��H���
);

int main(int arg, char *argv[])
{
/* ���[�v�p�ϐ� */
int i, j, k;

/* �����p�ϐ� */
int time;
/* ���{�b�g�̍��W�ƌ��������邽�߂̕ϐ� */
int x;
int y;
int muki;

/* ���{�b�g�̂��鎞���ɂ�����o�́i�߂�l�j�����邽�߂̕ϐ� */
struct robot_output temp;

/* ������i�܂��邽�߂̃L�[�{�[�h���͗p�ϐ� */
int enter;

/* ���H�̃f�[�^�\������� */
/* 2�����z����g���B�ʘH�͂O�A�ǂ́|1�ŕ\�����B */
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

/* �X�^�[�g�ƃS�[���̔z��v�f�ɂ��ꂼ��ɑΉ��������l���� */
data[1][0] = START;
data[9][10]= GOAL;

/* ���H��\������ */
for(i=0; i < MAX_TATE; i++){
	for(j=0; j < MAX_YOKO; j++)
		switch(data[i][j]){
			case KABE:
				printf("��");
				break;
			case TURO:
				printf("�@");
				break;
			case START:
				printf("�X");
				break;
			case GOAL:
				printf("�S");
				break;
		}
	printf("\n");
}
printf("\n");

/* ���{�b�g�̍��W�ƌ����������� */
   x=1;
   y=1;
muki=EAST;
data[y][x]=1;

   /* ���H���������{�b�g�A���S���Y���̋L�q */

/* while����p����1�X�e�b�v�����ԍX�V */
while(1){
   /* ���{�b�g��1�X�e�b�v�ɂ��A1������s���� */
   temp = robot(x,y,muki,data);
   x = temp.x;
   y = temp.y;
   muki = temp.muki;

   /* ���H�ƌo�H��\������ */
	for(i=0; i < MAX_TATE; i++){
		for(j=0; j < MAX_YOKO; j++)
			/* robot�֐��ŋL�^���Ă������ʂ������W�̒ʉ߉񐔂�\������d�g�� */
			if(data[i][j] > 0){
				printf("%2d",data[i][j]);
			}else{
			switch(data[i][j]){
				case KABE:
					printf("��");
					break;
				case TURO:
					printf("�@");
					break;
				case START:
					printf("�X");
					break;
				case GOAL:
					printf("�S");
					break;
			}
			}
		printf("\n");
	}
	/* ���H��2�����z��Ƀ��{�b�g�̂��ǂ����o�H�̃f�[�^���㏑�����ĕ\�� */
	/* ���̃X�e�b�v�ɐi�� */
	printf("Time is %4d. Next Time: Hit �u1 Key�v!",time);
//	scanf("%d",&enter);
//	if(enter != 1) break;



    Sleep(100); // ������(�������������قǑ������삷��)




	time = time + 1;
}

   return(0);
}

////////////////////////////////////////////////////////////////////////
/* �֐�robot                                                          */
/* ���͂Ƃ��āA���H�f�[�^�ƌ������̃��{�b�g�̍��W�ƌ�����             */
/* �^������ƁA�Z���T�[�����g���Ď��̍��W�Ɉړ����邩�A           */
/* ���̊p�x������]������ړ����郍�{�b�g����������B               */
/* �o�͂Ƃ��āA�����̃��{�b�g�̍��W�ƌ����A�O�㍶�E�̕ǂ̏󋵂�Ԃ� */
////////////////////////////////////////////////////////////////////////
struct robot_output robot( //���o�̓o�[�W����
//int robot(
	int x,
	int y,
	int muki,
	int data[MAX_TATE][MAX_YOKO]
)
{
/* ���{�b�g�̑O�㍶�E�̃Z���T�[���̂��߂̕ϐ� */
int mae, ushiro, migi, hidari;
struct robot_output output;
/* ���{�b�g�̎��̎����̈ʒu������A�Z���T�[�������Ă���           */
/* ���߂̕ϐ��ŁA�Ō�Ƀ��{�b�g�͂��̕ϐ��ɓ����Ă���f�[�^���o�͂��� */

/* �������̍��W�ƌ������烍�{�b�g���͂̃Z���T�[�����擾���� */
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
/* ���{�b�g�̑O�㍶�E�̏󋵂�\������ */
printf("�O=%2d ��=%2d �E=%2d ��=%2d ����=%2d \n",mae, ushiro, migi, hidari, muki);

/* ���͂̏󋵂ɂ�蓮������肷�� */

//�ꍇ�����������̂ŃP�[�X�����g�����Ƃɂ���E�E�E�Ƃ͏��������̂̂܂���if���ō��

if(mae != -10){ //-10�̓S�[���n�_��\��

   //��������E��@

   if(migi != -1){

        //�@90�x�E��]


        muki = muki+1;
        muki = muki%4;


        //�A�O�i



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



             //�@�O�i



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

                  //�@270�x�E��]


                  muki = muki + 3;
                  muki = muki % 4;


                  //�A�O�i



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



             //�@180�x�E��]


             muki = muki + 2;
             muki = muki % 4;


             //�A�O�i



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



    //�����܂ŉE��@


}else{
      // �S�[���ɓ��������̂ł��������Ȃ�
}


//90�x�E��]�p�̃v���O����
 //muki = muki+1;
 //muki = muki%4;


//180�x�E��]�p�̃v���O����
 //muki = muki + 2;
 //muki = muki % 4;


//90�x����]�p = 270�x�E��]�p�̃v���O����
 //muki = muki + 3;
 //muki = muki % 4;

/* �X�V��̍��W��ʉ߂������Ƃ�\�����߉񐔂��J�E���g */
data[y][x]=data[y][x]+1;



// �O�i�p�̃v���O����

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

/* ���C���֐��Ƀ��{�b�g�̓����̍��W�A�����A�O�㍶�E�̕ǂ̏󋵂�ϐ�output�ŕԂ� */
output.x = x;
output.y = y;
output.muki = muki;
output.mae = mae;
output.ushiro = ushiro;
output.migi = migi;
output.hidari = hidari;
return output;
}
