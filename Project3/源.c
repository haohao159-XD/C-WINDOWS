#include"windows.h"
#include<stdio.h>
#define PageSizex 260 //窗口宽
#define PageSizey 220 //窗口高

//#ifdef _UNICODE
//#if defined _M_IX86
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#elif defined _M_X64
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#else
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#endif
//#endif
LRESULT CALLBACK CallBack(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);//声明回调函数
int hButton_gongneng[100]={0};
int hFont;
int hbuttonN[100] = { 0 };
//WINAPI: 调用约定，调用约定，主要是参数的入栈顺序，这个栈空间的清理者，
// 在其他代码中 __stdcall, APIENTRY都是一样，可以转到定义查看，
// 
//句柄：一个数 ；作用：窗口的唯一标志

int WINAPI WinMain(
	HINSTANCE hInstance, //当前实例句柄 英文单词:hinstance
	HINSTANCE hPreinstance, //前一个实例的句柄
	LPTSTR ipcmdline,  //传递给系统胡命令行参数
	int ncmdshow  //默认为1，指定窗口的打开方式：隐藏，最大，最小显示
)
{
	//初始化窗口类
	WNDCLASSEX  wc; // window class extra与 wndclass 的扩展
	HWND hWnd; //窗口句柄 Handle to the window
	MSG mSg; //信息接受 message

	//配置窗口类
	wc.cbClsExtra = 0;  //对窗口类的额外空间
	wc.cbSize = sizeof(WNDCLASSEX); //类的结构体大小
	wc.hInstance = hInstance; //当前窗口实例句柄
	wc.hCursor = NULL;// 光标 不需要设为 NULL 也可自行加载系统光标 LoadCursor(NULL,IDC_HAND);
	wc.cbWndExtra = 0; //对窗口的额外空间
	wc.hIcon = NULL;//图标 不需要可以设为NULL 可以将NULL换为系统默认图标 LoadIcon(NULL,IDI_ERROR); 
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;    //背景更换颜色 
	wc.hIconSm = NULL; //小图标 不需要设为 NULL 也可自行加载系统图标 LoadIcon(NULL, IDI_ERROR); 
	wc.lpfnWndProc = CallBack; //回调函数名
	wc.lpszClassName = "FirstWin"; //名字不能重复！给操作系统看的
	wc.lpszMenuName = NULL;  //菜单名 不需要设为 NULL
	wc.style = CS_HREDRAW | CS_VREDRAW; //窗口类样式：hrizons redaw | vertical redaw 垂直刷新和水平刷新 

	//12个成员少一个不可以！！！

	//注册窗口对象
	//RegisterClassEx(&wc) 返回数据类型 ATOM unsigned short 注册成功返回非0，失败返回0
	if (0 == RegisterClassEx(&wc))
	{

		int a = GetLastError(); //函数生成对应的错误码，可用工具查询注册失败的原因 

		return 0;
	};

	//创建窗口      lp 是一个指针的意思   指针英文：pointer 
	hWnd = CreateWindowEx(
		WS_EX_TOPMOST, //dwExStyle 窗口附加属性：显示在最顶层
		"FirstWin", // lpClassName 窗口类的名字， 给系统看的，同前 
		"WINDOWS DEMO",  //lpWindowName 窗口显示的名字
		WS_OVERLAPPEDWINDOW,  //dwStyle 窗口创建风格 可以一个或多个用 | 连接
		100, //x 指定窗口的显示的x坐标，相对与桌面
		100, //y 指定窗口的显示的y坐标，相对与桌面
		PageSizex, //nWidth 窗口宽度
		PageSizey, //nheight 窗口高度
		NULL,  //hWndParent 副窗口句柄
		NULL, //hMenu 窗口菜单
		hInstance, //hInstance 当前实例句柄
		NULL //lpParam 
	);

	hFont = CreateFont(
		-15/*高度*/, -7.5/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,
		FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,
		DEFAULT_CHARSET,  //使用默认字符集
		OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管
		DEFAULT_QUALITY,  //默认输出质量
		FF_DONTCARE,  //不指定字体族*/
		TEXT("微软雅黑")  //字体名
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
		hWnd,//父窗口
		-1,//HMENU消息ID
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
		hWnd,//父窗口
		-2,//HMENU消息ID
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
		hWnd,//父窗口
		-3,//HMENU消息ID
		hInstance,
		NULL
	);
	hButton_gongneng[3] = CreateWindowEx(
		0,
		"BUTTON",
		"÷",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		30,//y
		50,//long
		20,//high
		hWnd,//父窗口
		-4,//HMENU消息ID
		hInstance,
		NULL
	);
	hButton_gongneng[4] = CreateWindowEx(
		0,
		"BUTTON",
		"×",
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT,
		165,//x
		55,//y
		50,//long
		20,//high
		hWnd,//父窗口
		-5,//HMENU消息ID
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
		hWnd,//父窗口
		-6,//HMENU消息ID
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
		hWnd,//父窗口
		-7,//HMENU消息ID
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
		hWnd,//父窗口
		-8,//HMENU消息ID
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
	//SendMessage(hButton_gongneng[0], WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体
	CreateWindowEx(
		0,
		"STATIC",
		"计算器DEMO",
		WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | WS_BORDER /*带边框*/,
		0,
		0,
		300,
		25,
		hWnd,
		NULL,
		hInstance,
		NULL
	);
	if (NULL == hWnd) //窗口句柄  窗口唯一标识
	{
		return 0;
	}

	//显示窗口
	ShowWindow(hWnd, ncmdshow); //指定窗口显示方式，这里为1，标准显示窗口样式 同上
	// 隐藏返回0， 可视返回非0	

//得到消息
	while (GetMessage(
		&mSg, //指向信息体的指针
		NULL,// 指定窗口句柄 选择处理那个窗口的消息  NULL/非NULL的区别，全部句柄接受
		0, 0 //设定处理消息的范围 这里为全部范围
	))
	{

		TranslateMessage(&mSg); //翻译消息，将按键虚拟消息转化为字符消息并寄送到调用线程的信息队列里，

		DispatchMessage(&mSg); //分发消息到系统，系统去调用我们的回调函数callback(过程函数） 
		//信息类型 ：标准消息 命令消息 通知消息 自定义消息

	}

	return 0;
}


// LRESULT 处理消息产生的一个有符号值	CALLBACK调用约定

LRESULT CALLBACK CallBack(

	HWND hWnd, //窗口句柄
	UINT nMsg, //消息ID  UIMT 其实就是一个unsigned int
	WPARAM wParam, LPARAM lParam //每条信息所带的两条数据 'word'数据类型，’long‘数据类型
)
{
	int wmId, wmEvent;
	PAINTSTRUCT pst;
	HDC hDC;
	switch (nMsg)
	{
	case WM_DESTROY:
		MessageBox(0,"FUCK YOU","ERROR", MB_OK);
		PostQuitMessage(0); //在点击窗口关闭键 返回0给Getmessage函数 停止信息接受循环
		//点击叉叉 会经过  WM_CLOSE->WM_DESTORY->WM_QUIT  处理消息 
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch (wmId) {
			//case 2:  //按下按钮
			//	break;
		case -1:
		{

			break;
		}
		case 1:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 2:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 3:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 4:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 5:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 6:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 7:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 8:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		case 9:
		{
			printf("%d", wmId);
			MessageBeep(MB_ICONHAND);//轻dideng
			break;
		}
		default:
			//不处理的消息一定要交给 DefWindowProc 处理。
			return DefWindowProc(hWnd, nMsg, wParam, lParam);
		}

	}
	return DefWindowProc(hWnd, nMsg, wParam, lParam);//默认系统处理其他消息
	//保持系统连贯性

}

