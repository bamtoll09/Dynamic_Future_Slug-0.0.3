#include "RGEngine.h"
#include "TestScene.h"

int main(void)
{
	RGApp->Initialize(L"Dynamic Future Slug", 1280, 720, false);
	RGAsset->Initialize();

	RGApp->ChangeScene(new TestScene());

	while (RGGraphic->Validate())
	{
		if (RGGraphic->Process())
		{
			RGApp->Update();

			if (RGGraphic->BeginScene())
			{
				RGApp->Render();

				RGGraphic->EndScene();
			}
		}
	}

	return 0;
}