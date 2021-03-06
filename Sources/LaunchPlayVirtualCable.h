//
//  LaunchPlayVirtualCable.h
//  LaunchPlayVST
//
//  Created by Fred G on 07/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef LaunchPlayVST_LaunchPlayVirtualCable_h
#define LaunchPlayVST_LaunchPlayVirtualCable_h

#include "LaunchPlay.h"
#include "MIDIHelpers.h"
#include <boost/scoped_array.hpp>

namespace LaunchPlayVST {
    
    class LaunchPlayVirtualCable : public LaunchPlayBase {
		VstInt32 channelOffsetNumber_;
		boost::scoped_array<char> buffer_;

		static VstInt32 activeInstancesCount_, maxMessageSize_;

        void closeAllMessageQueues();
	protected: 
        void onTick(double tempo, double ppq, double sampleRate, VstInt32 sampleOffset);
    public:
        LaunchPlayVirtualCable(audioMasterCallback audioMaster);
        ~LaunchPlayVirtualCable();
        
        VstPlugCategory getPlugCategory() { return kPlugCategEffect; }
        bool getEffectName(char *name);
        VstInt32 canDo(char *text);

		float getParameter(VstInt32 index);
        void setParameter(VstInt32 index, float value);
        void getParameterName(VstInt32 index, char *text);
        void getParameterDisplay(VstInt32 index, char *text);
        bool canParameterBeAutomated (VstInt32 index) { return false; } 

		VstInt32 getNumMidiInputChannels();
		VstInt32 getNumMidiOutputChannels();

		VstInt32 getChunk(void **data, bool isPreset = false);	
		VstInt32 setChunk(void *data, VstInt32 byteSize, bool isPreset=false);

		void open();
        void close();
        void processReplacing (float **inputs, float **outputs, VstInt32 sampleFrames);
    };
    
} // } namespace LaunchPlayVST

#endif
