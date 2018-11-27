#pragma once

#include "idither.h"

class SierraDither : public IDither
{
public:
	void execute(QImage &img, palette &plt) override;
};