/*
* (C) HuXiaozhong 2018
*
* ��ʱ�����ݽṹ
* time_mode����ʱ��ģʽ
* need_time�������ʱʱ�䣬��λ��MS��
* machine_time��΢���������ڣ�uS��
* fp������Ƶ�ʣ�MHZ��
* time����ʱ����λ�͵�λ��ɵ����ֽ�����
*/
typedef struct {
	short time_mode;
	short need_time;
	float fp;
	float machine_time;
	int time;
} Timer;

/*
* ��ʼ��������/��ʱ���������
*/
void init_timer(Timer *timer);

/*
* ���������/��ʱ��������
*/
void timer_output(Timer *timer);
