#include "stdafx.h"
#include "Shader.h"
#include "OComPointer.h"
#include <d3dcompiler.h>
#include "globals.h"




ID3DBlob* Shader::Compile(ID3D11Device *dev,std::wstring fileName,std::string entryPoint,EntryType type)
{
	UINT flags=0;//D3DCOMPILE_ENABLE_STRICTNESS;
	#if defined( DEBUG ) || defined( _DEBUG )
		flags |= D3DCOMPILE_DEBUG;
	#endif
	LPCSTR profile;
	
	

	//Check if file exist
	System::String^ str=gcnew System::String(fileName.c_str());
	if (!System::IO::File::Exists(str))
	{
		throw gcnew System::Exception(System::String::Format(L"Compile File {0} does not exist.",str));
	}


	// Prefer higher CS shader profile when possible as CS 5.0 provides better performance on 11-class hardware.
    if (type == VS)
		profile = ( dev->GetFeatureLevel() >= D3D_FEATURE_LEVEL_11_0 ) ? "vs_5_0" : "vs_4_0";
    else if (type == PS)
		profile = ( dev->GetFeatureLevel() >= D3D_FEATURE_LEVEL_11_0 ) ? "ps_5_0" : "ps_4_0";
	else
		profile = ( dev->GetFeatureLevel() >= D3D_FEATURE_LEVEL_11_0 ) ? "cs_5_0" : "cs_4_0";

	
	
	ID3DBlob* shaderBlob = nullptr;
    OComPointer<ID3DBlob> errorBlob = nullptr;
    D3DCompileFromFile( fileName.c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE,
                              entryPoint.c_str(), profile, flags, 0, &shaderBlob, &errorBlob);
	if (errorBlob!=NULL)
	{
			throw gcnew System::Exception(gcnew System::String((char*) errorBlob->GetBufferPointer()));
	}
		
	return shaderBlob;

}