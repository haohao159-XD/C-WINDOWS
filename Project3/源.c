#include"windows.h"
#define PageSizex 1000 //���ڿ�
#define PageSizey 600 //���ڳ�
LRESULT CALLBACK CallBack(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);//�����ص�����


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
		"���ĵ�һ������",  //lpWindowName ������ʾ������
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
	PAINTSTRUCT pst;
	HDC hDC;
	switch (nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0); //�ڵ�����ڹرռ� ����0��Getmessage���� ֹͣ��Ϣ����ѭ��
		//������ �ᾭ��  WM_CLOSE->WM_DESTORY->WM_QUIT  ������Ϣ 
		break;
	}
	return DefWindowProc(hWnd, nMsg, wParam, lParam);//Ĭ��ϵͳ����������Ϣ
	//����ϵͳ������

}

