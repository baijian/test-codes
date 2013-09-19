#!/usr/bin/env python
import pickle
#import cPickle as pickle

color = {"a":"red", "b":"yellow"}
pickle.dump( color, open( "color.p", "wb" ) )

colors = pickle.load( open( "color.p", "rb" ) )
