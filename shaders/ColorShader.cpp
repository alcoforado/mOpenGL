
#include "ColorShader.h"



	ColorShader::ColorShader(Direct3DBase *base)
		:_mngr(0,sizeof(Vertice))
	{
		_dx=base;
		_mngr.CreateBatch();
		OComPointer<ID3D10Blob> errorMsg=NULL;
		int shaderFlags=0;
		
		OComPointer<ID3DBlob> psByteCode,vsByteCode;
		vsByteCode=this->Compile(_dx->m_d3dDevice,L"./Color.hlsl","VS",Shader::VS);
		psByteCode=this->Compile(_dx->m_d3dDevice,L"./Color.hlsl","PS",Shader::PS);


		//Create the pixel and vertice shaders
		_dx->m_d3dDevice->CreateVertexShader(vsByteCode->GetBufferPointer(),vsByteCode->GetBufferSize(),NULL,&_vs);
		_dx->m_d3dDevice->CreatePixelShader(psByteCode->GetBufferPointer(),psByteCode->GetBufferSize(),NULL,&_ps);

		//Get the buffer reference
		// Fill in a buffer description.
		assert(sizeof(Vertice) % 16 == 0);
	D3D11_BUFFER_DESC cbDesc = {
		sizeof( Vertice), //SIZE OF BUFFER
		D3D11_USAGE_DEFAULT,
		D3D11_BIND_CONSTANT_BUFFER,
		0, //NO CPU ACCESS
		0, //MISC
		0}; //BYTE STRIDE


		// Create the constant  buffer.
		CheckError(_dx->m_d3dDevice->CreateBuffer( &cbDesc, NULL,&_cb));

    
	}

	void ColorShader::SetContext(ID3D11DeviceContext *context)
	{
		// Prepare All the stages
		context->IASetInputLayout(_layout);
        context->VSSetShader(_vs,NULL,0);
        context->PSSetShader(_ps,NULL,0);
		context->VSSetConstantBuffers(0,1,&_cb);

	}

	 void  ColorShader::Clear()
     {
            _mngr.ClearAllBatches();
     }

     void  ColorShader::AddShape(Shape* sh,VectorFunction4x4 *vf)
     {
            _mngr.GetBatch(0).AddShape(sh);
			sh->GetBindInfo()->_shaderData.f=vf;
     }


	 void  ColorShader::SetWorldViewProj(Matrix4x4 &worldViewProj)
        {
			XMMATRIX data=worldViewProj.Transpose();
			_dx->m_d3dContext->UpdateSubresource(_cb,0,NULL,&data,0,0);
        }

	 void  ColorShader::UpdateGeometryBuffers()
        {
			_mngr.ComputeAllBatches();
            
			_vB.if_free();
			_iB.if_free();

			D3D11_BUFFER_DESC cbDesc = {
			_mngr.getVerticesData().size()*sizeof(Vertice), //SIZE OF BUFFER
			D3D11_USAGE_DEFAULT,
			D3D11_BIND_VERTEX_BUFFER,
			0, //NO CPU ACCESS
			0, //MISC
			0}; //BYTE STRIDE


			//Init data
			D3D11_SUBRESOURCE_DATA initData;
			initData.pSysMem=&(_mngr.getVerticesData()[0]);
			initData.SysMemPitch=0;
			initData.SysMemSlicePitch=0;
			
			// Create the vertex  buffer.
			UINT sl=sizeof(Vertice);
			UINT off=0;
			CheckError(_dx->m_d3dDevice->CreateBuffer( &cbDesc, &initData,&_vB));
			
			
			//Index Buffer desc 
			cbDesc.ByteWidth=_mngr.getIndicesData().size()*sizeof(Index);
			cbDesc.BindFlags=D3D11_BIND_INDEX_BUFFER;
			//Index Init Data
			initData.pSysMem=&(_mngr.getIndicesData()[0]);
			//Create the Index Buffer
			CheckError(_dx->m_d3dDevice->CreateBuffer( &cbDesc, &initData,&_iB));
			
			//Bind the vertice and indices buffers
			_dx->m_d3dContext->IASetIndexBuffer(_iB,DXGI_FORMAT_R32_UINT,0);
			_dx->m_d3dContext->IASetVertexBuffers(0,1,&_vB,&sl,&off);
			_dx->m_d3dContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			
       }
	    void  ColorShader::draw()
        {
			if (_mngr.NeedUpdate())
               this->UpdateGeometryBuffers();
			if (!_mngr.getIndicesData().empty())
                _dx->m_d3dContext->DrawIndexed(_mngr.getIndicesData().size(),0,0);
        }

        void ColorShader::test()
        {

        }



