#!/usr/pkg/bin/perl
## swap.pm for  in 
## 
## Made by fabrice jumarie
## Login   <jumari_f@epita.fr>
## 
## Started on  Thu Mar 14 11:00:39 2002 fabrice jumarie
## Last update Tue Apr 16 15:26:47 2002 Fabrice jumarie
##

sub	lprint
{
    my $i;
    print "[List A]\n";
    foreach $i (@l_a)
    {
	print "$i ";
    }
    print "\n[List B]\n";
    foreach $i (@l_b)
    {
	print "$i ";
    }
    print "\n\n";
}

sub	op_sa
{
    if ($#l_a > -1)
    {
	$elem = shift @l_a;
	splice (@l_a, 1, 0, $elem);
    }
}

sub	op_sb
{
    if ($#l_b > -1)
    {
	$elem = shift @l_b;
	splice (@l_b, 1, 0, $elem);
    }
}

sub	op_pa
{
    if ($#l_b > -1)
    {
	$elem = shift @l_b;
	unshift @l_a, $elem;
    }
}

sub	op_pb
{
    if ($#l_a > -1)
    {
	$elem = shift @l_a;
	unshift @l_b, $elem;
    }
}

sub	op_ss
{
    op_sa();
    op_sb();
}

sub	op_ra
{
    $elem = shift @l_a;
    push @l_a, $elem;
}

sub	op_rb
{
    $elem = shift @l_b;
    push @l_b, $elem;
}

sub	op_rr
{
    op_ra();
    op_rb();
}

sub	op_rra
{
    $elem = pop @l_a;
    unshift @l_a, $elem;
}

sub	op_rrb
{
    $elem = pop @l_b;
    unshift @l_b, $elem;
}

sub	op_rrr
{
    op_rra();
    op_rrb();
}

sub	init_func
{
    $func_list{"sa"} = "op_sa";
    $func_list{"sb"} = "op_sb";
    $func_list{"pa"} = "op_pa";
    $func_list{"pb"} = "op_pb";
    $func_list{"ss"} = "op_ss";
    $func_list{"ra"} = "op_ra";
    $func_list{"rb"} = "op_rb";
    $func_list{"rr"} = "op_rr";
    $func_list{"rra"} = "op_rra";
    $func_list{"rrb"} = "op_rrb";
    $func_list{"rrr"} = "op_rrr";
}

sub	zprint($)
{
    print $_[0];
    print TTXT $_[0];
}

sub	open_file($)
{
    my($file) = @_;
    my (@T);
    open(FF, $file) or die "No Test File ($file): $!\n";
    @T = <FF>;
    close (FF);
    return (@T);
}

1;
