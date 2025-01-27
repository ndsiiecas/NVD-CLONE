void
CVE_2011_0079_VULN_ReadbackManagerD3D10::ProcessTasks()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  HANDLE handles[] = { mTaskSemaphore, mShutdownEvent };
  
  while (true) {
    DWORD result = ::WaitForMultipleObjects(2, handles, FALSE, INFINITE);
    if (result != WAIT_OBJECT_0) {
      return;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }

    ::EnterCriticalSection(&mTaskMutex);
    ReadbackTask *nextReadbackTask = mPendingReadbackTasks[0].forget();
    mPendingReadbackTasks.RemoveElementAt(0);
    ::LeaveCriticalSection(&mTaskMutex);

    // We want to block here until the texture contents are available, the
    // easiest thing is to simply map and unmap.
    D3D10_MAPPED_TEXTURE2D mappedTex;
    nextReadbackTask->mReadbackTexture->Map(0, D3D10_MAP_READ, 0, &mappedTex);
    nextReadbackTask->mReadbackTexture->Unmap(0);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // We can only send the update to the sink on the main thread, so post an
    // event there to do so. Ownership of the task is passed from
    // mPendingReadbackTasks to ReadbackResultWriter here.
fclose(para_fp);
    nsCOMPtr<nsIThread> thread = do_GetMainThread();
    thread->Dispatch(new ReadbackResultWriter(nextReadbackTask),
                     nsIEventTarget::DISPATCH_NORMAL);
  }
}
