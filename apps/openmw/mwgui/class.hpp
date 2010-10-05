#ifndef MWGUI_CLASS_H
#define MWGUI_CLASS_H

#include <components/esm_store/store.hpp>

#include <openengine/gui/layout.hpp>

#include <MyGUI.h>

#include "widgets.hpp"

namespace MWWorld
{
    class Environment;
}

/*
  This file contains the dialogs for choosing a class.
  Layout is defined by resources/mygui/openmw_chargen_class_layout.xml.
 */

namespace MWGui
{
    using namespace MyGUI;

    class PickClassDialog : public OEngine::GUI::Layout
    {
    public:
        PickClassDialog(MWWorld::Environment& environment, MyGUI::IntSize gameWindowSize);

        const std::string &getClassId() const { return currentClassId; }
        void setClassId(const std::string &classId);

        void setNextButtonShow(bool shown);
        void open();

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Back button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventBack;

        /** Event : Dialog finished, OK button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventDone;

    protected:
        void onSelectClass(MyGUI::List* _sender, size_t _index);

        void onOkClicked(MyGUI::Widget* _sender);
        void onBackClicked(MyGUI::Widget* _sender);

    private:
        void updateClasses();
        void updateStats();

        MWWorld::Environment& environment;

        MyGUI::StaticImagePtr classImage;
        MyGUI::ListPtr        classList;
        MyGUI::StaticTextPtr  specializationName;
        Widgets::MWAttributePtr favoriteAttribute0, favoriteAttribute1;
        Widgets::MWSkillPtr   majorSkill0, majorSkill1, majorSkill2, majorSkill3, majorSkill4;
        Widgets::MWSkillPtr   minorSkill0, minorSkill1, minorSkill2, minorSkill3, minorSkill4;

        std::string currentClassId;
    };

    class SelectSpecializationDialog : public OEngine::GUI::Layout
    {
    public:
        SelectSpecializationDialog(MWWorld::Environment& environment, MyGUI::IntSize gameWindowSize);

        ESM::Class::Specialization getSpecializationId() const { return specializationId; }

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Cancel button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventCancel;

        /** Event : Dialog finished, specialization selected.\n
            signature : void method()\n
        */
        EventHandle_Void eventItemSelected;

    protected:
        void onSpecializationClicked(MyGUI::Widget* _sender);
        void onCancelClicked(MyGUI::Widget* _sender);

    private:
        MyGUI::WidgetPtr      specialization0, specialization1, specialization2;

        ESM::Class::Specialization specializationId;
    };

    class SelectAttributeDialog : public OEngine::GUI::Layout
    {
    public:
        SelectAttributeDialog(MWWorld::Environment& environment, MyGUI::IntSize gameWindowSize);

        ESM::Attribute::AttributeID getAttributeId() const { return attributeId; }
        Widgets::MWAttributePtr getAffectedWidget() const { return affectedWidget; }
        void setAffectedWidget(Widgets::MWAttributePtr widget) { affectedWidget = widget; }

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Cancel button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventCancel;

        /** Event : Dialog finished, attribute selected.\n
            signature : void method()\n
        */
        EventHandle_Void eventItemSelected;

    protected:
        void onAttributeClicked(Widgets::MWAttributePtr _sender);
        void onCancelClicked(MyGUI::Widget* _sender);

    private:
        Widgets::MWAttributePtr attribute0, attribute1, attribute2, attribute3,
                                attribute4, attribute5, attribute6, attribute7;
        Widgets::MWAttributePtr affectedWidget;

        ESM::Attribute::AttributeID attributeId;
    };

    class SelectSkillDialog : public OEngine::GUI::Layout
    {
    public:
        SelectSkillDialog(MWWorld::Environment& environment, MyGUI::IntSize gameWindowSize);

        ESM::Skill::SkillEnum getSkillId() const { return skillId; }
        Widgets::MWSkillPtr getAffectedWidget() const { return affectedWidget; }
        void setAffectedWidget(Widgets::MWSkillPtr widget) { affectedWidget = widget; }

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Cancel button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventCancel;

        /** Event : Dialog finished, skill selected.\n
            signature : void method()\n
        */
        EventHandle_Void eventItemSelected;

    protected:
        void onSkillClicked(Widgets::MWSkillPtr _sender);
        void onCancelClicked(MyGUI::Widget* _sender);

    private:
        Widgets::MWSkillPtr combatSkill0, combatSkill1, combatSkill2, combatSkill3, combatSkill4,
                            combatSkill5, combatSkill6, combatSkill7, combatSkill8;
        Widgets::MWSkillPtr magicSkill0, magicSkill1, magicSkill2, magicSkill3, magicSkill4,
                            magicSkill5, magicSkill6, magicSkill7, magicSkill8;
        Widgets::MWSkillPtr stealthSkill0, stealthSkill1, stealthSkill2, stealthSkill3, stealthSkill4,
                            stealthSkill5, stealthSkill6, stealthSkill7, stealthSkill8;
        Widgets::MWSkillPtr affectedWidget;

        ESM::Skill::SkillEnum skillId;
    };

    class DescriptionDialog : public OEngine::GUI::Layout
    {
    public:
        DescriptionDialog(MWWorld::Environment& environment, MyGUI::IntSize gameWindowSize);

        std::string getTextInput() const { return textEdit ? textEdit->getOnlyText() : ""; }
        void setTextInput(const std::string &text) { if (textEdit) textEdit->setOnlyText(text); }

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Dialog finished, OK button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventDone;

    protected:
        void onOkClicked(MyGUI::Widget* _sender);

    private:
        MWWorld::Environment& environment;

        MyGUI::EditPtr textEdit;
    };

    class CreateClassDialog : public OEngine::GUI::Layout
    {
    public:
        CreateClassDialog(MWWorld::Environment& environment, MyGUI::IntSize gameWindowSize);
        virtual ~CreateClassDialog();

//        const std::string &getClassId() const { return currentClassId; }
//        void setClassId(const std::string &classId);

        void setNextButtonShow(bool shown);
        void open();

        // Events
        typedef delegates::CDelegate0 EventHandle_Void;

        /** Event : Back button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventBack;

        /** Event : Dialog finished, OK button clicked.\n
            signature : void method()\n
        */
        EventHandle_Void eventDone;

    protected:
        void onOkClicked(MyGUI::Widget* _sender);
        void onBackClicked(MyGUI::Widget* _sender);

        void onSpecializationClicked(MyGUI::WidgetPtr _sender);
        void onSpecializationSelected();
        void onAttributeClicked(Widgets::MWAttributePtr _sender);
        void onAttributeSelected();
        void onSkillClicked(Widgets::MWSkillPtr _sender);
        void onSkillSelected();
        void onDescriptionClicked(MyGUI::Widget* _sender);
        void onDescriptionEntered();
        void onDialogCancel();

    private:
        MWWorld::Environment& environment;

        MyGUI::EditPtr          editName;
        MyGUI::WidgetPtr        specializationName;
        Widgets::MWAttributePtr favoriteAttribute0, favoriteAttribute1;
        Widgets::MWSkillPtr     majorSkill0, majorSkill1, majorSkill2, majorSkill3, majorSkill4;
        Widgets::MWSkillPtr     minorSkill0, minorSkill1, minorSkill2, minorSkill3, minorSkill4;
        std::vector<Widgets::MWSkillPtr> skills;
        std::string             description;

        SelectSpecializationDialog *specDialog;
        SelectAttributeDialog *attribDialog;
        SelectSkillDialog *skillDialog;
        DescriptionDialog *descDialog;

        ESM::Class::Specialization specializationId;
    };
}
#endif