<?php /* Smarty version 2.6.14, created on 2011-04-21 08:13:32
         compiled from tiki-edit_help_tool.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'escape', 'tiki-edit_help_tool.tpl', 12, false),array('modifier', 'cat', 'tiki-edit_help_tool.tpl', 25, false),array('modifier', 'default', 'tiki-edit_help_tool.tpl', 25, false),array('function', 'cycle', 'tiki-edit_help_tool.tpl', 25, false),array('block', 'tr', 'tiki-edit_help_tool.tpl', 27, false),)), $this); ?>

<div class="quicktag">
<?php echo '
<script type="text/javascript">
<!--
function taginsert(area_name,tagid)
{
//fill variables
'; ?>

  var tag = new Array();
  <?php unset($this->_sections['qtg']);
$this->_sections['qtg']['name'] = 'qtg';
$this->_sections['qtg']['loop'] = is_array($_loop=$this->_tpl_vars['quicktags']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['qtg']['show'] = true;
$this->_sections['qtg']['max'] = $this->_sections['qtg']['loop'];
$this->_sections['qtg']['step'] = 1;
$this->_sections['qtg']['start'] = $this->_sections['qtg']['step'] > 0 ? 0 : $this->_sections['qtg']['loop']-1;
if ($this->_sections['qtg']['show']) {
    $this->_sections['qtg']['total'] = $this->_sections['qtg']['loop'];
    if ($this->_sections['qtg']['total'] == 0)
        $this->_sections['qtg']['show'] = false;
} else
    $this->_sections['qtg']['total'] = 0;
if ($this->_sections['qtg']['show']):

            for ($this->_sections['qtg']['index'] = $this->_sections['qtg']['start'], $this->_sections['qtg']['iteration'] = 1;
                 $this->_sections['qtg']['iteration'] <= $this->_sections['qtg']['total'];
                 $this->_sections['qtg']['index'] += $this->_sections['qtg']['step'], $this->_sections['qtg']['iteration']++):
$this->_sections['qtg']['rownum'] = $this->_sections['qtg']['iteration'];
$this->_sections['qtg']['index_prev'] = $this->_sections['qtg']['index'] - $this->_sections['qtg']['step'];
$this->_sections['qtg']['index_next'] = $this->_sections['qtg']['index'] + $this->_sections['qtg']['step'];
$this->_sections['qtg']['first']      = ($this->_sections['qtg']['iteration'] == 1);
$this->_sections['qtg']['last']       = ($this->_sections['qtg']['iteration'] == $this->_sections['qtg']['total']);
?>
  tag[<?php echo $this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['tagId']; ?>
]='<?php echo ((is_array($_tmp=$this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['taginsert'])) ? $this->_run_mod_handler('escape', true, $_tmp, 'javascript') : smarty_modifier_escape($_tmp, 'javascript')); ?>
';
  <?php endfor; endif; ?>
//done
<?php echo '  
  insertAt(area_name,tag[tagid]);
}
-->
</script>
'; ?>

<a href="javascript:toggleBlock('quicktags<?php echo $this->_tpl_vars['qtnum']; ?>
');" class="link"><img src="img/icons/plus.gif" border='0' alt='+' />&nbsp;Quicktags ...</a><br /><br />

<div id='quicktags<?php echo $this->_tpl_vars['qtnum']; ?>
' <?php if ($this->_tpl_vars['showtags']): ?>style="display:block;"<?php else: ?>style="display:none;"<?php endif; ?>>
<div>
<?php echo smarty_function_cycle(array('name' => ((is_array($_tmp='cycle')) ? $this->_run_mod_handler('cat', true, $_tmp, $this->_tpl_vars['qtnum']) : smarty_modifier_cat($_tmp, $this->_tpl_vars['qtnum'])),'values' => ((is_array($_tmp=@$this->_tpl_vars['qtcycle'])) ? $this->_run_mod_handler('default', true, $_tmp, ",,,</div><div>") : smarty_modifier_default($_tmp, ",,,</div><div>")),'advance' => false,'print' => false), $this);?>

<?php unset($this->_sections['qtg']);
$this->_sections['qtg']['name'] = 'qtg';
$this->_sections['qtg']['loop'] = is_array($_loop=$this->_tpl_vars['quicktags']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['qtg']['show'] = true;
$this->_sections['qtg']['max'] = $this->_sections['qtg']['loop'];
$this->_sections['qtg']['step'] = 1;
$this->_sections['qtg']['start'] = $this->_sections['qtg']['step'] > 0 ? 0 : $this->_sections['qtg']['loop']-1;
if ($this->_sections['qtg']['show']) {
    $this->_sections['qtg']['total'] = $this->_sections['qtg']['loop'];
    if ($this->_sections['qtg']['total'] == 0)
        $this->_sections['qtg']['show'] = false;
} else
    $this->_sections['qtg']['total'] = 0;
if ($this->_sections['qtg']['show']):

            for ($this->_sections['qtg']['index'] = $this->_sections['qtg']['start'], $this->_sections['qtg']['iteration'] = 1;
                 $this->_sections['qtg']['iteration'] <= $this->_sections['qtg']['total'];
                 $this->_sections['qtg']['index'] += $this->_sections['qtg']['step'], $this->_sections['qtg']['iteration']++):
$this->_sections['qtg']['rownum'] = $this->_sections['qtg']['iteration'];
$this->_sections['qtg']['index_prev'] = $this->_sections['qtg']['index'] - $this->_sections['qtg']['step'];
$this->_sections['qtg']['index_next'] = $this->_sections['qtg']['index'] + $this->_sections['qtg']['step'];
$this->_sections['qtg']['first']      = ($this->_sections['qtg']['iteration'] == 1);
$this->_sections['qtg']['last']       = ($this->_sections['qtg']['iteration'] == $this->_sections['qtg']['total']);
?>
<a title="<?php $this->_tag_stack[] = array('tr', array()); $_block_repeat=true;smarty_block_tr($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start();  echo $this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['taglabel'];  $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_tr($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>" href="javascript:taginsert('<?php echo $this->_tpl_vars['area_name']; ?>
','<?php echo $this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['tagId']; ?>
');"><img
src='<?php echo $this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['tagicon']; ?>
' alt='<?php $this->_tag_stack[] = array('tr', array()); $_block_repeat=true;smarty_block_tr($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start();  echo $this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['taglabel'];  $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_tr($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>' title='<?php $this->_tag_stack[] = array('tr', array()); $_block_repeat=true;smarty_block_tr($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat);while ($_block_repeat) { ob_start();  echo $this->_tpl_vars['quicktags'][$this->_sections['qtg']['index']]['taglabel'];  $_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo smarty_block_tr($this->_tag_stack[count($this->_tag_stack)-1][1], $_block_content, $this, $_block_repeat); }  array_pop($this->_tag_stack); ?>' border='0' /></a>
<?php echo smarty_function_cycle(array('name' => ((is_array($_tmp='cycle')) ? $this->_run_mod_handler('cat', true, $_tmp, $this->_tpl_vars['qtnum']) : smarty_modifier_cat($_tmp, $this->_tpl_vars['qtnum']))), $this);?>

<?php endfor; endif; ?>
<a title="special chars" class="link" href="#" onclick="javascript:window.open('tiki-special_chars.php?area_name=<?php echo $this->_tpl_vars['area_name']; ?>
','','menubar=no,width=252,height=25');"><img
src='images/ed_charmap.gif' alt='special characters' title='special characters' border='0' /></a>
</div>
<?php if ($this->_tpl_vars['tiki_p_admin'] == 'y'): ?>
<br /><a href="tiki-admin_quicktags.php" class="link">admin quicktags</a>
<?php endif; ?>
</div>
</div>