DWORD WINAPI PlayVideo(LPVOID lpParam){

	CVideoPlayerDlg* pThis = (CVideoPlayerDlg*)lpParam;

	CvCapture* pCapture;
	IplImage* pFrame;

	pCapture = cvCreateFileCapture("ŒÅË¿ÄÐÊ¿.mov");

	if (pCapture == NULL)
	{
		return -1;
	}

	pFrame = cvQueryFrame(pCapture);
	while (pFrame)
	{
		WaitForSingleObject(start_event, INFINITE);
		start_event.SetEvent();
		if (terminate_flag == -1)
		{
			terminate_flag = 0;
			_endthreadex(0);
		};
		pThis->Display(pFrame, IDC_STATIC);
		Sleep(33);
		pFrame = cvQueryFrame(pCapture);
	}

	cvReleaseCapture(&pCapture);

}