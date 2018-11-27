#pragma once

#include "idither.h"

class TwoRowSierraDither : public IDither
{
public:
	void execute(QImage &img, palette &plt) override;
};