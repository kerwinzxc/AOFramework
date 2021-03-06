
cbuffer vsBuffer : register(b0)
{
	float	g_width;
	float	g_height;
	float2	g_dummy;
};


struct VSInput
{
	float3	pos	: POSITION;
	float2	uv	: TEXCOORD;
};

struct VSOutput
{
	float4 pos	: SV_POSITION;
	float2 uv0	: TEXCOORD0;
	float2 uv1	: TEXCOORD1;
	float2 uv2	: TEXCOORD2;
	float2 uv3	: TEXCOORD3;
	float2 uv4	: TEXCOORD4;
	float2 uv5	: TEXCOORD5;
	float2 uv6	: TEXCOORD6;
	float2 uv7	: TEXCOORD7;
};


VSOutput main(VSInput In)
{
	VSOutput Out = (VSOutput)0;

	Out.pos = float4(In.pos, 1);
	Out.uv0 = In.uv + float2(-1.0f  * g_width, 0.0f);
	Out.uv1 = In.uv + float2(-3.0f  * g_width, 0.0f);
	Out.uv2 = In.uv + float2(-5.0f  * g_width, 0.0f);
	Out.uv3 = In.uv + float2(-7.0f  * g_width, 0.0f);
	Out.uv4 = In.uv + float2(-9.0f  * g_width, 0.0f);
	Out.uv5 = In.uv + float2(-11.0f * g_width, 0.0f);
	Out.uv6 = In.uv + float2(-13.0f * g_width, 0.0f);
	Out.uv7 = In.uv + float2(-15.0f * g_width, 0.0f);

	return Out;
}