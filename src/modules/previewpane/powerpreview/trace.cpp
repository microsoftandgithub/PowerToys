#include "pch.h"
#include "trace.h"
#include <string>

/*
*
* This file captures the telemetry for the File Explorer Custom Renders project.
* The following telemetry is to be captured for this library:
* (1.) Is the previewer enabled.  
* (2.) File rendered per user in 24 hrs per file time (one for MD, one for SVG)
* (3.) Crashes.
*
*/

TRACELOGGING_DEFINE_PROVIDER(
    g_hProvider,
    "Microsoft.PowerToys",
    // {38e8889b-9731-53f5-e901-e8a7c1753074}
    (0x38e8889b, 0x9731, 0x53f5, 0xe9, 0x01, 0xe8, 0xa7, 0xc1, 0x75, 0x30, 0x74),
    TraceLoggingOptionProjectTelemetry());

void Trace::RegisterProvider()
{
    TraceLoggingRegister(g_hProvider);
}

void Trace::UnregisterProvider()
{
    TraceLoggingUnregister(g_hProvider);
}

void Trace::PreviewHandlerEnabled(bool enabled, LPCWSTR previewHandlerName)
{
    TraceLoggingWrite(
        g_hProvider,
        "PowerPreview_TweakUISettings_Enabled",
        TraceLoggingWideString(previewHandlerName, "PreviewHanlder_FileType"),
        TraceLoggingBoolean(enabled, "Enabled"),
        ProjectTelemetryPrivacyDataTag(ProjectTelemetryTag_ProductAndServicePerformance),
        TraceLoggingBoolean(TRUE, "UTCReplace_AppSessionGuid"),
        TraceLoggingKeyword(PROJECT_KEYWORD_MEASURE));
}

void Trace::PowerPreviewSettingsUpDateFailed(LPCWSTR SettingsName)
{
    TraceLoggingWrite(
        g_hProvider,
        "PowerPreview_TweakUISettings_FailedUpdatingSettings",
        TraceLoggingWideString(SettingsName, "ExceptionMessage"),
        ProjectTelemetryPrivacyDataTag(ProjectTelemetryTag_ProductAndServicePerformance),
        TraceLoggingBoolean(TRUE, "UTCReplace_AppSessionGuid"),
        TraceLoggingKeyword(PROJECT_KEYWORD_MEASURE));
}

void Trace::SetConfigInvalidJSON(const char* exceptionMessage)
{
    TraceLoggingWrite(
        g_hProvider,
        "PowerPreview_TweakUISettings_SetConfig__InvalidJSONGiven",
        TraceLoggingString(exceptionMessage, "ExceptionMessage"),
        ProjectTelemetryPrivacyDataTag(ProjectTelemetryTag_ProductAndServicePerformance),
        TraceLoggingBoolean(TRUE, "UTCReplace_AppSessionGuid"),
        TraceLoggingKeyword(PROJECT_KEYWORD_MEASURE));
}

void Trace::Destroyed()
{
    TraceLoggingWrite(
        g_hProvider,
        "PowerPreview_TweakUISettings_Destroyed",
        ProjectTelemetryPrivacyDataTag(ProjectTelemetryTag_ProductAndServicePerformance),
        TraceLoggingBoolean(TRUE, "UTCReplace_AppSessionGuid"),
        TraceLoggingKeyword(PROJECT_KEYWORD_MEASURE));
}

void Trace::InitSetErrorLoadingFile(const char* exceptionMessage) 
{
    TraceLoggingWrite(
        g_hProvider,
        "PowerPreview_TweakUISettings_InitSet__ErrorLoadingFile",
        TraceLoggingString(exceptionMessage, "ExceptionMessage"),
        ProjectTelemetryPrivacyDataTag(ProjectTelemetryTag_ProductAndServicePerformance),
        TraceLoggingBoolean(TRUE, "UTCReplace_AppSessionGuid"),
        TraceLoggingKeyword(PROJECT_KEYWORD_MEASURE));
}

