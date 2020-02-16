#pragma once

#include <Tiger.h>

class GameLayer : public Tiger::Layer {
public:
	GameLayer() : Tiger::Layer("Game Layer") {}
	~GameLayer();

	virtual void onAttach() override;
	virtual void onDetach() override;

	virtual void onUpdate() override;
	virtual void onEvent(Tiger::Event& event) override;

	virtual void onDebugGUIRender() override;
private:
	Tiger::Ref<Tiger::VertexArray> vao;
	Tiger::Ref<Tiger::VertexBuffer> buffer;
	Tiger::Ref<Tiger::Shader> shader;
};