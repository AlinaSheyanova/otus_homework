#pragma once

/**
 * @brief The IUserAction class represents an interface for user actions.
 *
 * This class provides two pure virtual member functions: Execute and Undo.
 * The Execute function is responsible for performing the user action, while the Undo function
 * undoes the user action. Classes that implement this interface can be used to encapsulate
 * different types of user actions and perform them in a consistent manner.
 *
 * This interface is meant to be used as a base class for other user action classes.
 *
 * @note This class is meant to be subclassed and should not be used directly.
 */
class IUserAction
{
public:
    /**
     * @brief Executes the user action.
     *
     * This function is responsible for performing the user action. Subclasses of IUserAction
     * should override this function to provide their own implementation.
     *
     * @note This function must be implemented in the subclass.
     */
    virtual void Execute() {};

    /**
     * @brief Undoes the user action.
     *
     * This function is responsible for undoing the user action.
     *
     * @note This function must be implemented in the subclass.
     *
     * @see IUserAction::Execute()
     */
    virtual void Undo() {};

    /**
     * @brief The IUserAction class represents an interface for user actions.
     *
     * This class provides two pure virtual member functions: Execute and Undo.
     * The Execute function is responsible for performing the user action, while the Undo function
     * undoes the user action. Classes that implement this interface can be used to encapsulate
     * different types of user actions and perform them in a consistent manner.
     *
     * This interface is meant to*/
    virtual ~IUserAction() = default;
};




