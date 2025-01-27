BEGIN_WORKERS_NAMESPACE

JSObject*
CVE_2013_0774_PATCHED_CreateDedicatedWorkerGlobalScope(JSContext* aCx)
{
int origin_a, origin_aa[4];
  using namespace mozilla::dom;

  WorkerPrivate* worker = GetWorkerPrivateFromContext(aCx);
  JS_ASSERT(worker);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  JSObject* global =
    JS_NewGlobalObject(aCx, DedicatedWorkerGlobalScope::Class(),
                       GetWorkerPrincipal());
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

  if (worker->IsChromeWorker()) {
    if (!chromeworker::InitClass(aCx, global, workerProto, false) ||
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        !DefineChromeWorkerFunctions(aCx, global) ||
        !DefineOSFileConstants(aCx, global)) {
      return NULL;
    }
  }

  // Init other classes we care about.
  if (!events::InitClasses(aCx, global, false) ||
      !file::InitClasses(aCx, global) ||
      !exceptions::InitClasses(aCx, global) ||
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
