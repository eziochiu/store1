// license:BSD-3-Clause
// copyright-holders:Fabio Priuli
#ifndef MAME_BUS_VCS_SCHARGER_H
#define MAME_BUS_VCS_SCHARGER_H

#pragma once

#include "rom.h"
#include "imagedev/cassette.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> a26_rom_ss_device

class a26_rom_ss_device : public a26_rom_base_device
{
public:
	a26_rom_ss_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	virtual void install_memory_handlers(address_space *space) override;
	uint8_t read(offs_t offset);

private:
	virtual void device_start() override;
	virtual void device_reset() override;

	virtual void device_add_mconfig(machine_config &config) override;

	required_device<cassette_image_device> m_cassette;

	uint8_t read_byte(uint32_t offset);
	void tap(offs_t offset);

	int m_base_banks[2];
	uint8_t m_reg;
	uint8_t m_write_delay;
	bool m_ram_write_enabled;
	bool m_rom_enabled;
	uint16_t m_last_address_bus;
	uint32_t m_address_bus_changes;
};


// device type definition
DECLARE_DEVICE_TYPE(A26_ROM_SUPERCHARGER, a26_rom_ss_device)

#endif // MAME_BUS_VCS_SCHARGER_H
