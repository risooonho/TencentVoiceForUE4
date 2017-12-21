// Fill out your copyright notice in the Description page of Project Settings.

#include "TeamRoomNotify.h"

UTeamRoomNotify::UTeamRoomNotify(const FObjectInitializer& ObjectInitializer) :UObject(ObjectInitializer)
{
	//VoiceClient = ArgVoiceClient;
}

UTeamRoomNotify::~UTeamRoomNotify()
{

}

void UTeamRoomNotify::OnJoinRoom(GCloudVoiceCompleteCode code, const char *roomName, int memberID)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnJoinRoom"));
	//VoiceClient->OpenMic();
	//VoiceClient->OpenSpeaker();
}

void UTeamRoomNotify::OnStatusUpdate(GCloudVoiceCompleteCode status, const char *roomName, int memberID)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnStatusUpdate"));
}

void UTeamRoomNotify::OnQuitRoom(GCloudVoiceCompleteCode code, const char *roomName)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnQuitRoom"));
	//VoiceClient->CloseSpeaker();
	//VoiceClient->CloseMic();
}

void UTeamRoomNotify::OnMemberVoice(const unsigned int *members, int count)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnMemberVoice"));
}

void UTeamRoomNotify::OnMemberVoice(const char *roomName, unsigned int member, int status)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnMemberVoice"));
}

void UTeamRoomNotify::OnUploadFile(GCloudVoiceCompleteCode code, const char *filePath, const char *fileID)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnUploadFile"));
}

void UTeamRoomNotify::OnDownloadFile(GCloudVoiceCompleteCode code, const char *filePath, const char *fileID)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnDownloadFile"));
}

void UTeamRoomNotify::OnPlayRecordedFile(GCloudVoiceCompleteCode code, const char *filePath)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnPlayRecordedFile"));
}

void UTeamRoomNotify::OnApplyMessageKey(GCloudVoiceCompleteCode code)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnApplyMessageKey"));
}

void UTeamRoomNotify::OnSpeechToText(GCloudVoiceCompleteCode code, const char *fileID, const char *result)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnSpeechToText"));
}

void UTeamRoomNotify::OnRecording(const unsigned char* pAudioData, unsigned int nDataLength)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnRecording"));
}

void UTeamRoomNotify::OnStreamSpeechToText(GCloudVoiceCompleteCode code, int error, const char * result, const char * voicePath)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnStreamSpeechToText"));
}

void UTeamRoomNotify::OnRoleChanged(GCloudVoiceCompleteCode code, const char *roomName, int memberID, int role)
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("UTeamRoomNotify::OnRoleChanged"));
}
