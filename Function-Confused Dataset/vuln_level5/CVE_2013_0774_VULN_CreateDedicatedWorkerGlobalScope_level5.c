BEGIN_WORKERS_NAMESPACE

JSObject*
CVE_2013_0774_VULN_CreateDedicatedWorkerGlobalScope(JSContext* aCx)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  using namespace mozilla::dom;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

  WorkerPrivate* worker = GetWorkerPrivateFromContext(aCx);
  JS_ASSERT(worker);

  JSObject* global =
    JS_NewGlobalObject(aCx, DedicatedWorkerGlobalScope::Class(),
                       GetWorkerPrincipal());
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  if (!global) {
    return NULL;
  }

  JSAutoCompartment ac(aCx, global);

  // Make the private slots now so that all our instance checks succeed.
  if (!DedicatedWorkerGlobalScope::InitPrivate(aCx, global, worker)) {
    return NULL;
  }

  // Proto chain should be:
  //   global -> DedicatedWorkerGlobalScope
  //          -> WorkerGlobalScope
  //          -> EventTarget
  //          -> Object

  JSObject* eventTargetProto =
    EventTargetBinding_workers::GetProtoObject(aCx, global, global);
  if (!eventTargetProto) {
    return NULL;
  }

  JSObject* scopeProto =
    WorkerGlobalScope::InitClass(aCx, global, eventTargetProto);
fclose(para_fp);
  if (!scopeProto) {
    return NULL;
  }

  JSObject* dedicatedScopeProto =
    DedicatedWorkerGlobalScope::InitClass(aCx, global, scopeProto);
  if (!dedicatedScopeProto) {
    return NULL;
  }

  if (!JS_SetPrototype(aCx, global, dedicatedScopeProto)) {
    return NULL;
  }

  JSObject* workerProto = worker::InitClass(aCx, global, eventTargetProto,
                                            false);
  if (!workerProto) {
    return NULL;
  }

  if (worker->IsChromeWorker() &&
      (!chromeworker::InitClass(aCx, global, workerProto, false) ||
       !DefineChromeWorkerFunctions(aCx, global))) {
    return NULL;
  }

  if (!DefineOSFileConstants(aCx, global)) {
    return NULL;
  }

  // Init other classes we care about.
  if (!events::InitClasses(aCx, global, false) ||
      !file::InitClasses(aCx, global) ||
      !exceptions::InitClasses(aCx, global) ||
      !location::InitClass(aCx, global) ||
      !imagedata::InitClass(aCx, global) ||
      !navigator::InitClass(aCx, global)) {
    return NULL;
  }

  // Init other paris-bindings.  Use GetProtoObject so the proto will
  // be correctly cached in the proto cache.  Otherwise we'll end up
  // double-calling CreateInterfaceObjects when we actually create an
  // object which has these protos, which breaks things like
  // instanceof.
  if (!FileReaderSyncBinding_workers::GetProtoObject(aCx, global, global) ||
      !XMLHttpRequestBinding_workers::GetProtoObject(aCx, global, global) ||
      !XMLHttpRequestUploadBinding_workers::GetProtoObject(aCx, global, global)) {
    return NULL;
  }

  if (!JS_DefineProfilingFunctions(aCx, global)) {
    return NULL;
  }

  return global;
}
