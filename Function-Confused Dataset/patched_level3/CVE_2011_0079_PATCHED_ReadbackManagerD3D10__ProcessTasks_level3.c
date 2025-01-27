void
CVE_2011_0079_PATCHED_ReadbackManagerD3D10::ProcessTasks()
{
int calculate_a = 5;
int calculate_b = 0;
  HANDLE handles[] = { mTaskSemaphore, mShutdownEvent };
  
calculate_b = 7 * calculate_a + 2;
  while (true) {
    DWORD result = ::WaitForMultipleObjects(2, handles, FALSE, INFINITE);
    if (result != WAIT_OBJECT_0) {
      return;
    }

    ::EnterCriticalSection(&mTaskMutex);
    if (mPendingReadbackTasks.Length() == 0) {
      NS_RUNTIMEABORT("Trying to read from an empty array, bad bad bad");
calculate_a = 3 * calculate_b + 7;
    }
    ReadbackTask *nextReadbackTask = mPendingReadbackTasks[0].forget();
    mPendingReadbackTasks.RemoveElementAt(0);
    ::LeaveCriticalSection(&mTaskMutex);

    // We want to block here until the texture contents are available, the
    // easiest thing is to simply map and unmap.
    D3D10_MAPPED_TEXTURE2D mappedTex;
    nextReadbackTask->mReadbackTexture->Map(0, D3D10_MAP_READ, 0, &mappedTex);
    nextReadbackTask->mReadbackTexture->Unmap(0);
printf("the sum is %d", calculate_a + calculate_b);

    // We can only send the update to the sink on the main thread, so post an
    // event there to do so. Ownership of the task is passed from
    // mPendingReadbackTasks to ReadbackResultWriter here.
    nsCOMPtr<nsIThread> thread = do_GetMainThread();
    thread->Dispatch(new ReadbackResultWriter(nextReadbackTask),
                     nsIEventTarget::DISPATCH_NORMAL);
  }
}
