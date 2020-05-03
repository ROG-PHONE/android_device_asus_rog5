/*
   Copyright (c) 2015, The Linux Foundation. All rights reserved.
   Copyright (C) 2020 The OmniRom Project.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <android-base/properties.h>
#include <android-base/logging.h>
#include "property_service.h"
#include <sys/resource.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

namespace android {
namespace init {

using android::base::GetProperty;
using android::init::property_set;

void property_override(const std::string& name, const std::string& value)
{
    size_t valuelen = value.size();

    prop_info* pi = (prop_info*) __system_property_find(name.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), valuelen);
    }
    else {
        int rc = __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
        if (rc < 0) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "__system_property_add failed";
        }
    }
}

void vendor_load_properties()
{
    std::string name;
    std::string country;
    LOG(INFO) << "Starting custom init";

    name = android::base::GetProperty("ro.product.vendor.name", "");
    country = android::base::GetProperty("gsm.operator.iso-country", "");
    LOG(INFO) << name;
    if (name == "WW_I001D") {
        property_override("ro.build.fingerprint", "asus/WW_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.system.build.fingerprint", "asus/WW_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.build.description", "WW_I001D-user 10 QKQ1.190825.002 17.0230.2002.32-0 release-keys");
        property_override("ro.product.model", "ASUS_I001DA");
        property_override("ro.product.system.model", "ASUS_I001DA");
        property_override("ro.product.system.name", "WW_I001D");
        property_override("ro.product.vendor.model", "ASUS_I001DA");
        property_override("ro.product.carrier", "ASUS-ASUS_I001D-WW");
        if (country == "in" || country == "in,*") {
            property_override("ro.product.model", "ASUS_I001DE");
            property_override("ro.product.system.model", "ASUS_I001DE");
            property_override("ro.product.vendor.model", "ASUS_I001DE");
            property_override("ro.config.versatility", "IN");
        }
        if (country == "us" || country == "us,*") {
            property_override("ro.product.model", "ASUS_I001D");
            property_override("ro.product.system.model", "ASUS_I001D");
            property_override("ro.product.system.name", "WW_I001D");
            property_override("ro.product.vendor.model", "ASUS_I001D");
            property_override("ro.config.versatility", "US");
        }
    }
    if (name == "RU_I01WD") {
        property_override("ro.build.fingerprint", "asus/RU_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.system.build.fingerprint", "asus/RU_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.build.description", "RU_I001D-user 10 QKQ1.190825.002 17.0230.2002.32-0 release-keys");
        property_override("ro.product.model", "ASUS_I001DB");
        property_override("ro.product.system.model", "ASUS_I001DB");
        property_override("ro.product.system.name", "RU_I001D");
        property_override("ro.product.vendor.model", "ASUS_I001DB");
        property_override("ro.product.carrier", "ASUS-ASUS_I001D-WW");
        property_override("ro.config.versatility", "RU");
    }
    if (name == "EU_I001D") {
        property_override("ro.build.fingerprint", "asus/EU_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.system.build.fingerprint", "asus/EU_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.build.description", "EU_I001D-user 10 QKQ1.190825.002 17.0230.2002.32-0 release-keys");
        property_override("ro.product.model", "ASUS_I001DC");
        property_override("ro.product.system.model", "ASUS_I001DC");
        property_override("ro.product.system.name", "EU_I001D");
        property_override("ro.product.vendor.model", "ASUS_I001DC");
        property_override("ro.product.carrier", "ASUS-ASUS_I001D-WW");
        property_override("ro.config.versatility", "EU");
    }
    if (name == "CN_I001D") {
        property_override("ro.build.fingerprint", "asus/CN_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.system.build.fingerprint", "asus/CN_I001D/ASUS_I001_1:10/QKQ1.190825.002/17.0230.2002.32-0:user/release-keys");
        property_override("ro.build.description", "CN_I001D-user 10 QKQ1.190825.002 17.0230.2002.32-0 release-keys");
        property_override("ro.product.model", "ASUS_I001DD");
        property_override("ro.product.system.model", "ASUS_I001DD");
        property_override("ro.product.system.name", "CN_I001D");
        property_override("ro.product.vendor.model", "ASUS_I001DD");
        property_override("ro.product.carrier", "ASUS-ASUS_I001D-WW");
        property_override("ro.config.versatility", "CN");
    }
}
}
}