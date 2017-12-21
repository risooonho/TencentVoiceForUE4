// Fill out your copyright notice in the Description page of Project Settings.

#include "VoiceClient.h"

UVoiceClient* UVoiceClient::VoiceClient = nullptr;

UVoiceClient::UVoiceClient()
{
	m_voiceengine = gcloud_voice::GetVoiceEngine();
}

UVoiceClient::~UVoiceClient()
{

}

void UVoiceClient::Tick(float DeltaTime)
{
	m_voiceengine->Poll();
}

FORCEINLINE bool UVoiceClient::IsTickable() const
{
	return true;
}

FORCEINLINE TStatId UVoiceClient::GetStatId() const
{
	return TStatId();
}

UVoiceClient * UVoiceClient::GetVoiceClient()
{
	if (nullptr == VoiceClient)
	{
		VoiceClient = NewObject<UVoiceClient>();
		VoiceClient->AddToRoot();
	}
	return VoiceClient;
}

bool UVoiceClient::SetAppInfo(const FString& appID, const FString& appKey, const FString& OpenID)
{
	//UE_LOG(TencentVoicePlugin, Display, TEXT("SetAppInfo return code %d!"), static_cast<int32>(m_voiceengine->SetAppInfo(TCHAR_TO_ANSI(*appID), TCHAR_TO_ANSI(*appKey), TCHAR_TO_ANSI(*OpenID))));

	if ((nullptr != m_voiceengine)
		&& (gcloud_voice::GCLOUD_VOICE_SUCC == m_voiceengine->SetAppInfo(TCHAR_TO_ANSI(*appID), TCHAR_TO_ANSI(*appKey), TCHAR_TO_ANSI(*OpenID))))
	{
		return true;
	}
	return false;
}

void UVoiceClient::InitVoiceEngine()
{
	//m_voiceengine->Init();
	UE_LOG(TencentVoicePlugin, Display, TEXT("InitVoiceEngine return code %d!"), static_cast<int32>(m_voiceengine->Init()));
	m_voiceengine->SetMode(gcloud_voice::IGCloudVoiceEngine::RealTime);
	m_voiceengine->SetServerInfo("udp://cn.voice.gcloudcs.com:10001");
}

void UVoiceClient::OnPause()
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("OnPause return code %d!"), static_cast<int32>(m_voiceengine->Pause()));
}

void UVoiceClient::OnResume()
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("OnResume return code %d!"), static_cast<int32>(m_voiceengine->Resume()));
}

bool UVoiceClient::SetNotify(UObject * NotifyToUse)
{
	class UTeamRoomNotify* TempNotify = NewObject<UTeamRoomNotify>();
	//UE_LOG(TencentVoicePlugin, Display, TEXT("SetNotify return code %d!"), static_cast<int32>(m_voiceengine->SetNotify(TempNotify)));
	//class MessageNotify* TempNotify = new class MessageNotify();
	
	if ((nullptr != TempNotify)
		&& (gcloud_voice::GCLOUD_VOICE_SUCC == m_voiceengine->SetNotify(TempNotify)))
	{
		CurrentNotify = TempNotify;
		return true;
	}
	return false;
}

UObject * UVoiceClient::GetNotify()
{
	return CurrentNotify;
}

bool UVoiceClient::JoinTeamRoom(const FString & RoomName, int32 msTimeout)
{
	//UE_LOG(TencentVoicePlugin, Display, TEXT("JoinTeamRoom return code %d!"), static_cast<int32>(m_voiceengine->JoinTeamRoom(TCHAR_TO_ANSI(*RoomName), msTimeout)));

	if (gcloud_voice::GCLOUD_VOICE_SUCC == m_voiceengine->JoinTeamRoom(TCHAR_TO_ANSI(*RoomName), msTimeout))
	{
		return true;
	}
	return false;
}

void UVoiceClient::OpenMic()
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("OpenMic return code %d!"), static_cast<int32>(m_voiceengine->OpenMic()));
}

void UVoiceClient::CloseMic()
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("CloseMic return code %d!"), static_cast<int32>(m_voiceengine->CloseMic()));
}

void UVoiceClient::OpenSpeaker()
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("OpenSpeaker return code %d!"), static_cast<int32>(m_voiceengine->OpenSpeaker()));
}

void UVoiceClient::CloseSpeaker()
{
	UE_LOG(TencentVoicePlugin, Display, TEXT("CloseSpeaker return code %d!"), static_cast<int32>(m_voiceengine->CloseSpeaker()));
}

bool UVoiceClient::QuitRoom(const FString & RoomName, int32 msTimeout)
{
	/*UE_LOG(TencentVoicePlugin, Display, TEXT("QuitRoom return code %d!"), static_cast<int32>(m_voiceengine->QuitRoom(TCHAR_TO_ANSI(*RoomName), msTimeout)));*/

	if (gcloud_voice::GCLOUD_VOICE_SUCC == m_voiceengine->QuitRoom(TCHAR_TO_ANSI(*RoomName), msTimeout))
	{
		return true;
	}
	return false;
}
