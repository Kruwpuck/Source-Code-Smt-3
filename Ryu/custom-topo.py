"""Custom topology example

Two directly connected switches plus a host for each switch:

   host --- switch --- switch --- host

Adding the 'topos' dict with a key/value pair to generate our newly defined
topology enables one to pass in '--topo=mytopo' from the command line.
"""

from mininet.topo import Topo

class MyTopo( Topo ):
    "Simple topology example."

    def build( self ):
        "Create custom topo."

        # left Slice
        h1 = self.addHost( 'h1' )
        h2 = self.addHost( 'h2' )
        h3 = self.addHost( 'h3' )
        h4 = self.addHost( 'h4' )
        s1 = self.addSwitch( 's1' )
        s4 = self.addSwitch( 's4' )
        s5 = self.addSwitch( 's5' )
        s10 = self.addSwitch( 's10' )
        s11 = self.addSwitch( 's11' )


        # left links
        self.addLink( h1, s10 )
        self.addLink( h2, s10 )
        self.addLink( h3, s11 )
        self.addLink( h4, s11 )
        self.addLink( s10, s4 )
        self.addLink( s10, s5 )
        self.addLink( s11, s4 )
        self.addLink( s11, s5 )
        self.addLink( s4, s1 )
        self.addLink( s5, s1 )

        # center Slice
        h5 = self.addHost( 'h5' )
        h6 = self.addHost( 'h6' )
        h7 = self.addHost( 'h7' )
        h8 = self.addHost( 'h8' )   
        s2 = self.addSwitch( 's2' )
        s6 = self.addSwitch( 's6' )
        s7 = self.addSwitch( 's7' )
        s12 = self.addSwitch( 's12' )
        s13 = self.addSwitch( 's13' )   

        # center links
        self.addLink( h5, s12 )
        self.addLink( h6, s12 )
        self.addLink( h7, s13 )
        self.addLink( h8, s13 )
        self.addLink( s12, s6 )
        self.addLink( s12, s7 )
        self.addLink( s13, s6 )
        self.addLink( s13, s7 )
        self.addLink( s6, s2 )
        self.addLink( s7, s2 )

        # right Slice
        h9 = self.addHost( 'h9' )
        h10 = self.addHost( 'h10' )
        h11 = self.addHost( 'h11' )
        h12 = self.addHost( 'h12' )    
        s3 = self.addSwitch( 's3' )
        s8 = self.addSwitch( 's8' )
        s9 = self.addSwitch( 's9' )
        s14 = self.addSwitch( 's14' )
        s15 = self.addSwitch( 's15' )

        # right links
        self.addLink( h9, s14 )
        self.addLink( h10, s14 )
        self.addLink( h11, s15 )
        self.addLink( h12, s15 )
        self.addLink( s15, s8 )
        self.addLink( s15, s9 )
        self.addLink( s14, s8 )
        self.addLink( s14, s9 )
        self.addLink( s8, s3 )
        self.addLink( s9, s3 )

        # interslice links
        self.addLink( s1, s3 )
        self.addLink( s1, s2 )
        self.addLink( s2, s1 )
        self.addLink( s2, s3 )
        self.addLink( s3, s1 )
        self.addLink( s3, s2 )


topos = { 'ihab': ( lambda: MyTopo() ) }
