#include"windows.h"
#include<stdio.h>
#define PageSizex 260 //���ڿ�
#define PageSizey 220 //���ڸ�

//#ifdef _UNICODE
//#if defined _M_IX86
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#elif defined _M_X64
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#else
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#endif
//#endif
LRESULT CALLBACK CallBack(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);//�����ص�����
int hButton_gongneng[100]={0};
int hFont;
int hbuttonN[100] = { 0 };
//WINAPI: ����Լ��������Լ������Ҫ�ǲ�������ջ˳�����ջ�ռ�������ߣ�
// ������������ __stdcall, APIENTRY����һ��������ת������鿴��
// 
//�����һ���� �����ã����ڵ�Ψһ��־

int WINAPI WinMain(
	HINSTANCE hInstance, //��ǰʵ����� Ӣ�ĵ���:hinstance
	HINSTANCE hPreinstance, //ǰһ��ʵ���ľ��
	LPTSTR ipcmdline,  //���ݸ�ϵͳ�������в���
	int ncmdshow  //Ĭ��Ϊ1��ָ�����ڵĴ򿪷�ʽ�����أ������С��ʾ
)
{
	//��ʼ��������
	WNDCLASSEX  wc; // window class extra�� wndclass ����չ
	HWND hWnd; //���ھ�� Handle to the window
	MSG mSg; //��Ϣ���� message

	//���ô�����
	wc.cbClsExtra = 0;  //�Դ�����Ķ���ռ�
	wc.cbSize = sizeof(WNDCLASSEX); //��Ľṹ���С
	wc.hInstance = hInstance; //��ǰ����ʵ�����
	wc.hCursor = NULL;// ��� ����Ҫ��Ϊ NULL Ҳ�����м���ϵͳ��� LoadCursor(NULL,IDC_HAND);
	wc.cbWndExtra = 0; //�Դ��ڵĶ���ռ�
	wc.hIcon = NULL;//ͼ�� ����Ҫ������ΪNULL ���Խ�NULL��ΪϵͳĬ��ͼ�� LoadIcon(NULL,IDI_ERROR); 
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;    //����������ɫ 
	wc.hIconSm = NULL; //Сͼ�� ����Ҫ��Ϊ NULL Ҳ�����м���ϵͳͼ�� LoadIcon(NULL, IDI_ERROR); 
	wc.lpfnWndProc = CallBack; //�ص�������
	wc.lpszClassName = "FirstWin"; //���ֲ����ظ���������ϵͳ����
	wc.lpszMenuName = NULL;  //�˵��� ����Ҫ��Ϊ NULL
	wc.style = CS_HREDRAW | CS_VREDRAW; //��������ʽ��hrizons redaw | vertical redaw ��ֱˢ�º�ˮƽˢ�� 

	//12����Ա��һ�������ԣ�����

	//ע�ᴰ�ڶ���
	//RegisterClassEx(&wc) ������������ ATOM unsigned short ע��ɹ����ط�0��ʧ�ܷ���0
	if (0 == RegisterClassEx(&wc))
	{

		int a = GetLastError(); //�������ɶ�Ӧ�Ĵ����룬���ù��߲�ѯע��ʧ�ܵ�ԭ�� 

		return 0;
	};

	//��������      lp ��һ��ָ�����˼   ָ��Ӣ�ģ�pointer 
	hWnd = CreateWindowEx(
		WS_EX_TOPMOST, //dwExStyle ���ڸ������ԣ���ʾ�����
		"FirstWin", // lpClassName ����������֣� ��ϵͳ���ģ�ͬǰ 
		"WINDOWS DEMO",  //lpWindowName ������ʾ������
		WS_OVERLAPPEDWINDOW,  //dwStyle ���ڴ������ ����һ�������� | ����
		100, //x ָ�����ڵ���ʾ��x���꣬���������
		100, //y ָ�����ڵ���ʾ��y���꣬���������
		PageSizex, //nWidth ���ڿ��
		PageSizey, //nheight ���ڸ߶�
		NULL,  //hWndParent �����ھ��
		NULL, //hMenu ���ڲ˵�
		hInstance, //hInstance ��ǰʵ�����
		NULL //lpParam 
	);

	hFont = CreateFont(
		-15/*�߶�*/, -7.5/*���*/, 0, 0, 400 /*һ�����ֵ��Ϊ400*/,
		FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,
		DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�
		DEFAULT_QUALITY,  //Ĭ���������
		FF_DONTCARE,  //��ָ��������*/
		TEXT("΢���ź�")  //������
	);

	hButton_gongneng[0] = CreateWindowEx(
		0,
		"BUTTON",
		"C",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		0,//x
		30,//y
		50,//long
		20,//high
		hWnd,//������
		-1,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[1] = CreateWindowEx(
		0,
		"BUTTON",
		"CE",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		55,//x
		30,//y
		50,//long
		20,//high
		hWnd,//������
		-2,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[2] = CreateWindowEx(
		0,
		"BUTTON",
		"BP",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		110,//x
		30,//y
		50,//long
		20,//high
		hWnd,//������
		-3,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[3] = CreateWindowEx(
		0,
		"BUTTON",
		"��",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		30,//y
		50,//long
		20,//high
		hWnd,//������
		-4,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[4] = CreateWindowEx(
		0,
		"BUTTON",
		"��",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		55,//y
		50,//long
		20,//high
		hWnd,//������
		-5,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[5] = CreateWindowEx(
		0,
		"BUTTON",
		"-",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		80,//y
		50,//long
		20,//high
		hWnd,//������
		-6,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[6] = CreateWindowEx(
		0,
		"BUTTON",
		"+",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		105,//y
		50,//long
		20,//high
		hWnd,//������
		-7,//HMENU��ϢID
		hInstance,
		NULL
	);
	hButton_gongneng[4] = CreateWindowEx(
		0,
		"BUTTON",
		"=",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		130,//y
		50,//long
		20,//high
		hWnd,//������
		-8,//HMENU��ϢID
		hInstance,
		NULL
	);
	hbuttonN[0] = CreateWindowEx(
		0,
		"BUTTON",
		"7",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		0,
		55,
		50,
		20,
		hWnd,
		7,
		hInstance,
		NULL
	);
	hbuttonN[1] = CreateWindowEx(
		0,
		"BUTTON",
		"8",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		55,
		55,
		50,
		20,
		hWnd,
		8,
		hInstance,
		NULL
	);
	hbuttonN[2] = CreateWindowEx(
		0,
		"BUTTON",
		"9",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		110,
		55,
		50,
		20,
		hWnd,
		9,
		hInstance,
		NULL
	);
	hbuttonN[3] = CreateWindowEx(
		0,
		"BUTTON",
		"4",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		0,
		80,
		50,
		20,
		hWnd,
		4,
		hInstance,
		NULL
	);
	hbuttonN[4] = CreateWindowEx(
		0,
		"BUTTON",
		"5",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		55,
		80,
		50,
		20,
		hWnd,
		5,
		hInstance,
		NULL
	);
	hbuttonN[5] = CreateWindowEx(
		0,
		"BUTTON",
		"6",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		110,
		80,
		50,
		20,
		hWnd,
		6,
		hInstance,
		NULL
	);

	hbuttonN[6] = CreateWindowEx(
		0,
		"BUTTON",
		"1",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		0,
		105,
		50,
		20,
		hWnd,
		1,
		hInstance,
		NULL
	);
	hbuttonN[7] = CreateWindowEx(
		0,
		"BUTTON",
		"2",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		55,
		105,
		50,
		20,
		hWnd,
		2,
		hInstance,
		NULL
	);
	hbuttonN[8] = CreateWindowEx(
		0,
		"BUTTON",
		"3",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		110,
		105,
		50,
		20,
		hWnd,
		3,
		hInstance,
		NULL
	);
	hbuttonN[9] = CreateWindowEx(
		0,
		"BUTTON",
		"0",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		55,
		130,
		50,
		20,
		hWnd,
		0,
		hInstance,
		NULL
	);
	hbuttonN[10] = CreateWindowEx(
		0,
		"BUTTON",
		"+/-",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		0,
		130,
		50,
		20,
		hWnd,
		10,
		hInstance,
		NULL
	);
	hbuttonN[11] = CreateWindowEx(
		0,
		"BUTTON",
		".",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		110,
		130,
		50,
		20,
		hWnd,
		11,
		hInstance,
		NULL
	);
	//SendMessage(hButton_gongneng[0], WM_SETFONT, (WPARAM)hFont, NULL);//���ð�ť����
	CreateWindowEx(
		0,
		"STATIC",
		"������DEMO",
		WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | WS_BORDER /*���߿�*/,
		0,
		0,
		300,
		25,
		hWnd,
		NULL,
		hInstance,
		NULL
	);
	if (NULL == hWnd) //���ھ��  ����Ψһ��ʶ
	{
		return 0;
	}

	//��ʾ����
	ShowWindow(hWnd, ncmdshow); //ָ��������ʾ��ʽ������Ϊ1����׼��ʾ������ʽ ͬ��
	// ���ط���0�� ���ӷ��ط�0	

//�õ���Ϣ
	while (GetMessage(
		&mSg, //ָ����Ϣ���ָ��
		NULL,// ָ�����ھ�� ѡ�����Ǹ����ڵ���Ϣ  NULL/��NULL������ȫ���������
		0, 0 //�趨������Ϣ�ķ�Χ ����Ϊȫ����Χ
	))
	{

		TranslateMessage(&mSg); //������Ϣ��������������Ϣת��Ϊ�ַ���Ϣ�����͵������̵߳���Ϣ�����

		DispatchMessage(&mSg); //�ַ���Ϣ��ϵͳ��ϵͳȥ�������ǵĻص�����callback(���̺����� 
		//��Ϣ���� ����׼��Ϣ ������Ϣ ֪ͨ��Ϣ �Զ�����Ϣ

	}

	return 0;
}


// LRESULT ������Ϣ������һ���з���ֵ	CALLBACK����Լ��

LRESULT CALLBACK CallBack(

	HWND hWnd, //���ھ��
	UINT nMsg, //��ϢID  UIMT ��ʵ����һ��unsigned int
	WPARAM wParam, LPARAM lParam //ÿ����Ϣ�������������� 'word'�������ͣ���long����������
)
{
	int wmId, wmEvent;
	PAINTSTRUCT pst;
	HDC hDC;
	switch (nMsg)
	{
	case WM_DESTROY:
		MessageBox(0,"FUCK YOU","ERROR", MB_OK);
		PostQuitMessage(0); //�ڵ�����ڹرռ� ����0��Getmessage���� ֹͣ��Ϣ����ѭ��
		//������ �ᾭ��  WM_CLOSE->WM_DESTORY->WM_QUIT  ������Ϣ 
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch (wmId) {
			//case 2:  //���°�ť
			//	break;
		case -1:
		{

			break;
		}
		case 1:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 2:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 3:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 4:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 5:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 6:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 7:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 8:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		case 9:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//��dideng
			break;
		}
		default:
			//���������Ϣһ��Ҫ���� DefWindowProc ����
			return DefWindowProc(hWnd, nMsg, wParam, lParam);
		}

	}
	return DefWindowProc(hWnd, nMsg, wParam, lParam);//Ĭ��ϵͳ����������Ϣ
	//����ϵͳ������

}

